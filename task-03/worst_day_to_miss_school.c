//Author: Arun Krishnan(AM.EN.U4CSE22004)

#include <stdio.h>

int main()
{
    //n->number of groups of schoolchildren
    int n;
    int k;
    int uber = 0;
    int arr[5] = {0};
    //Take the input n
    scanf("%d",&n);
    //Looping n times
    for(int i=0;i<n;i++)
    {
        //Taking inputs to j
        scanf("%d",&k);
        arr[k]++;
    }
    //The 4 group memebers need 1 uber as a whole
    uber = arr[4];
    //Now the 3 group members need 1 uber as a whole but there will be
    //space left so we fill the 1 remaining space with members from
    //group 1
    uber = uber + arr[3];
    //sending some students from group1 to uber with group3
    //then the ramaining students are stored in group1
    arr[1] = arr[1] - arr[3];
    //If the number of  ubers taken by group3 students exceeds
    //the number of group1 students then we set group1 as 0
    if(arr[1]<0)
    {
        arr[1]=0;
    }
    //Now we can take 2 sets of group2 members in a uber
    uber = uber+arr[2]/2;
    //If there are even no:of group2 members
    if(arr[2]%2==0)
    {
        //All members went on the uber
        arr[2]=0;
    }
    //Since there are odd no:of group2 people
    else
    {
        //There will be a group which is left behind
        arr[2]=1;
    }
    //Now storing each of remaining students to a[1]
    arr[1] = arr[1]+arr[2]*2;
    //Finding if group1 is divisible by 4 to see if we can allocate individual ubers
    if(arr[1]%4==0)
    {
        uber = uber+arr[1]/4;
    }
    //If incase the number of students in group1 is not a multiple of 4
    //then we need to allocate one more uber to the remaining memebers
    else
    {
        uber = uber+arr[1]/4+1;
    }
    //Print the final number of taxis
    printf("%d",uber);

    return 0;
}