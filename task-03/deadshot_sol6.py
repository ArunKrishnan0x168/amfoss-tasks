#Author: Arun Krishnan(AM.EN.U4CSE22004)

# Number of sets
n = 0

#Take n
n = int(input())

#Array of x points
x = []

#Array of y points
y = []

#Number of  vantage points
points = 0

#Take the set of x,y values

for i in range(n):
    cods = list(map(int,input().split()))
    x.append(cods[0])
    y.append(cods[1])

#Looping to find the vantage points
for j in range(n):
    right = False
    left = False
    upper = False
    lower = False
    for k in range(n):
        #Check if there is a left neighbour
        if x[j] > x[k] and y[j] == y[k]:
            left = True
        #Check if there is a right neighbour
        elif x[j] < x[k] and y[j] == y[k]:
            right = True
        #Check if there is an upper neighbour
        elif x[j] == x[k] and y[j] < y[k]:
            upper = True
        #Check if there is a lower neighbour
        elif x[j] == x[k] and y[j] > y[k]:
            lower = True
       
    #If the conditions are met 
    if right and left  and lower and upper:
        points = points+1
        
print(points)
    