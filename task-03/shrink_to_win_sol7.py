#Author: Arun Krishnan(AM.EN.U4CSE22004)

#Declare sum
sum = 0
#Declare conversions
conversions = 0
#Take the input
n = input()
while (len(n) > 1):
    sum = 0
    #ord() converts chars to their respective unicodes
    #Where eg ord("0") is 48 and ord("4") is 52
    for i in range(len(n)):
        sum = sum + (ord(n[ i ]) -ord('0'))
    #Converting integer sum to a string
    n = str(sum)
    #Incrementing conversion each time the loop runs
    conversions = conversions + 1
#Printing the final answer
print(conversions)
 
