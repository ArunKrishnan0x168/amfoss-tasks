#Author : Arun Krishnan(AM.EN.U4CSE22004)

t = int(input())

for i in range(t):

    zeroes = 0
    
    n = int(input())

    levels = list(map(int,input().split()))

   #Count the number of zeroes
    for j in range(n):
        if levels[j] == 0:
            zeroes=zeroes+1

     #Check wether if 0 is an element
    if 0 in levels:
        mana =  len(levels)-zeroes       
    #Check if there are duplicates
    elif(len(set(levels)) == len(levels)):
        mana = len(levels)+1
    #if there are duplicates
    else:
        mana = len(levels)
    
    print(mana)