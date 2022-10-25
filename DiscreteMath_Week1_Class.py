import matplotlib.pyplot as plt
import numpy as np
import time
import math



def recursive(n):
    if n <= 2:
        return 1
    else:
        return recursive(n - 1) + recursive(n - 2)


def table(n):
    ls = []
    if n == 0:
        return 1
    for i in range(0, n):
        if i <= 1:
            ls.append(1)
        else:
            ls.append(ls[i-1] + ls[i-2])
    return ls[n - 1]


def twovalues(n):
    a = b = 1
    for i in range(3, n + 1):
        b = b + a
        a = b - a
    return b


def analytic(n):
    a = (math.sqrt(5) + 1) / 2
    return (pow(a, n) - pow(1 - a, n))/math.sqrt(5)


# def matrix(n):
#



def timeit(func, n):
    start = time.time()
    func(n)
    end = time.time()
    return end - start


N = list(range(100))
N1 = [0, 10, 20, 30, 35]
T1 = [timeit(recursive, n) for n in N1]
T2 = [timeit(table, n) for n in N]
T3 = [timeit(analytic, n) for n in N]
T4 = [timeit(twovalues, n) for n in N]



plt.plot(N1, T1)
plt.plot(N, T2)
plt.plot(N, T3)
plt.plot(N, T4)
plt.xlabel('n')
plt.ylabel('Time (s)');
plt.legend(['Table', 'Analytic', 'Twovalues'])
plt.show()



# n = 9
# print(recursive(n))
# print(twovalues(n))
# print(table(n))
# print(analytic(n))
