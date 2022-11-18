#Author : Arun Krishnan(AM.EN.U4CSE22004)

#Such a number would be known as the lcm

import math

#to find the lcm
def lcm(n):
    a = 1
    for i in range(1,n+1):
        a = (a*i)//math.gcd(i,a)

    return a

T = int(input())

for i in range(T):
    N = int(input())
    result = lcm(N)
    print(result)
    