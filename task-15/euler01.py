#Author : Arun Krishnan(AM.EN.U4CSE22004)

#This function calculates the sum of multiples of p below n
#Concept made clear through https://www.mathblog.dk/project-euler-problem-1/
def div_by(n,p):
    a = n//p
    return p*(a*(a+1))//2    

T = int(input())

for i in range(T):
    n = int(input())
    #We'd have to subtract the sum of multiples of 15 as it would be counted twice
    print(div_by(n-1,3)+div_by(n-1,5)-div_by(n-1,15))
    

