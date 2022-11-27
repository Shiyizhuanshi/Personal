# This is the repo for IAC coursework Team4

---
#### Things to do:

- [x] Design a basic cpu structure (Lab4)
- [ ] Design cpu to implement R-Type instruction
- [ ] Design cpu to implement I-Type instruction
- [ ] Design cpu to implement S-Type instruction
- [ ] Design cpu to implement B-Type instruction
- [ ] Design cpu to implement U-Type instruction
- [ ] Design cpu to implement J-Type instruction
- [ ] Design cache for cpu
- [ ] Design bus for cpu

---

##### Background 

RISC-V has six types of instruction in total, they look like below:

<img width="980" alt="image" src="https://user-images.githubusercontent.com/100481494/202711466-7f65dcc5-bfb9-4e0a-81c8-e62fcbe05be8.png">


opcode
: Define the type of instruction

funct3 & funct7
: These two fields combined with opcode to determine what operation should be implemented 

rs1 & rs2
: Adress of register

rd
: Address of destination register

imm
: Constant value in instructions

---

#### Main goals

Here below are the instructions we need to implement for our cpu:

<img width="980" alt="image" src="https://user-images.githubusercontent.com/100481494/204151139-724ef69b-1746-4e2b-9067-148ec4c5a174.png">

<img width="980" alt="image" src="https://user-images.githubusercontent.com/100481494/204151252-6deb5314-c46e-49a9-abd3-db67b880831f.png
">

<img width="980" alt="image" src="https://user-images.githubusercontent.com/100481494/204151324-fdffd6bb-329e-48ee-adf2-c7b2ffe81697.png
">

<img width="980" alt="image" src="https://user-images.githubusercontent.com/100481494/204151355-8b0c2528-c180-44da-9dc4-345d537d0bef.png
">

