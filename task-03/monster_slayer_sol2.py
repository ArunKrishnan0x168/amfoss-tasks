#Author : Arun Krishnan(AM.EN.U4CSE22004)

#Take the number of groups
t = int(input())

for i in range(t):
    dup = 0
    #Take the number of monsters in each group
    n = int(input())
    #Take healths each of monsters in the each group
    health = list(map(int,input().split()))
    #Remove the first element if the first element in 0
    if(health[0]==0):
            health.pop(0)
    #Check if the elements are multiples of first element in the list
    for j in range(len(health)):
        if health[j]%health[0]==0:
            dup = dup+1;
    
    #Check if the array only has same elements
    if len(set(health))==1:
        print("YES")
    #Elements which are multiplies of first element
    elif dup==n:
        print("YES")
    #Nothing worked then
    else:
        print("NO")
    



