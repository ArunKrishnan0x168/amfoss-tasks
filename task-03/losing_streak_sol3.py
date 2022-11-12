#Author : Arun Krishnan(AM.EN.U4CSE22004)

import sys

#Factors array
factors = []

#Factorial function
def factorise(n):
    if n < 4:
        return n
    while n > 1:
        for i in range(2, int(2+n//2)):
            if i == (1 + n // 2):
                factors.append(n)
                n = n // n
            if n % i == 0:
                factors.append(i)
                n = n // i
                break
    return factors

#Take the input
cash = list(map(int,input().split()))

#Other than 2 and 3
other=False

#Find the number when the amount is divided by the particular number
# also make sure the first element is not 0 

if cash[0]!=0:
    factor = int(cash[1]/cash[0])   
elif cash[0]==0:
    print(-1)
    sys.exit()
    
#Factorise "factor" and store the values to factors
factorise(factor)

#Check if there are any other elements in factors other than 2 and 3
for k in factors:
    if k != 2 and k != 3:
        other = True
    else:
        break

#If the money he has and the amount needed is the same
if cash[0] == cash[1]:
    print(0)

#There aint no factors
elif len(factors)==0:
    print(-1)
    
#There are other factors other  than 2 and 3
elif other:
    print(-1)

#The total number of steps
else:
    #Number of steps
    print(factors.count(2)+factors.count(3))
