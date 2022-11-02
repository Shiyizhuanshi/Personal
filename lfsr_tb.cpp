#include "Vlfsr.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"


int main(int argc, char **argv, char **env){
    int i;
    int clk;

    Verilated::commandArgs(argc, argv);

    Vlfsr* top = new Vlfsr;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open ("lfsr.vcd");
    
    // init vbuddy
    if (vbdOpen()!=1) return (-1);
    vbdHeader("Lab 3: LFSR");

    top->clk = 1;
    top->rst = 0;
    top->en = 1;

    for (i=0; i<1000; i++){
        for (clk=0; clk<2; clk++){
            tfp->dump (2*i+clk);
            top->clk = !top->clk;
            top->eval ();
        }

        // ++++ Send count to Vbuddy
        // vbdHex(4, (int(top->count) >> 16) & 0xF);
        // vbdHex(3, (int(top->count) >> 8) & 0xF);
        // vbdHex(2, (int(top->count) >> 4) & 0xF);
        // vbdHex(1, int(top->count) & 0xF);
        

        // vbdPlot(int(top->dout), 0, 255);

        vbdBar(top->data_out & 0xFF);
        vbdHex(1, top->data_out & 0xF);
        vbdCycle(i+1);
        // end of Vbuddy section

        //change input simuli
        // top->rst = (i<2) | (i==15);
        vbdSetMode(1);
        top->en = vbdFlag();
        top->rst = (i<2);
            // either simulation finished, or 'q' is pressed
        if ((Verilated::gotFinish()) || (vbdGetkey()=='q')) 
        exit(0);                // ... exit if finish OR 'q' pressed
    }

    vbdClose();
    tfp->close();
    exit(0);
}
