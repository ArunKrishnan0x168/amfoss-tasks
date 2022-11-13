//Author: Arun Krishnan(AM.EN.U4CSE22004)

#include <iostream>

int main()
{
    //n->number of groups of schoolchildren
    int n;
    //Temp variable o
    int o;
    //The total number of ubers
    int uber = 0;
    //Take n
    std::cin >> n;
    //Array having info about each group
    //Initially all elements are 0
    int grp[5] = {0};
    //Getting info about each group
    for(int i=0;i<n;i++)
    {
        //updating index value by 1 each time a specific group has
        //entered
        std::cin >> o;
        grp[o]++;
    }
    //The 4 group memebers need 1 uber as a whole
    uber = grp[4];
    //Now the 3 group members need 1 uber as a whole but there will be
    //space left so we fill the 1 remaining space with members from
    //group 1
    uber = uber + grp[3];
    //sending some students from group1 to uber with group3
    //then the ramaining students are stored in group1
    grp[1] = grp[1] - grp[3];
    //If the number of  ubers taken by group3 students exceeds
    //the number of group1 students then we set group1 as 0
    if(grp[1]<0)
    {
        grp[1]=0;
    }
    //Now we can take 2 sets of group2 members in a uber
    uber = uber+grp[2]/2;
    //If there are even no:of group2 members
    if(grp[2]%2==0)
    {
        //All members went on the uber
        grp[2]=0;
    }
    //Since there are odd no:of group2 people
    else
    {
        //There will be a group which is left behind
        grp[2]=1;
    }
    //Now storing each of remaining students to a[1]
    grp[1] = grp[1]+grp[2]*2;
    //Finding if group1 is divisible by 4 to see if we can allocate individual ubers
    if(grp[1]%4==0)
    {
        uber = uber+grp[1]/4;
    }
    //If incase the number of students in group1 is not a multiple of 4
    //then we need to allocate one more uber to the remaining memebers
    else
    {
        uber = uber+grp[1]/4+1;
    }
    //Print the final number of ubers
    std::cout << uber << "\n";
    return 0;
}