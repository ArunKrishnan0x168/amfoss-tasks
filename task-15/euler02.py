#Author : Arun Krishnan(AM.EN.U4CSE22004)

T = int(input())

for i in range(T):
    N = int(input())
    f1 = 1
    f2 = 2
    sum = 0
    while(f2 < N):
        f0 = f1+f2
        f1 = f2
        f2 = f0
        if f1%2== 0:
            sum = sum + f1
    
    print(sum)

