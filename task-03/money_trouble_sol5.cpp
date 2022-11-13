//Author : Arun Krishnan(AM.EN.U4CSE22004)

#include <iostream>
#include <cmath>

int main()
{
    //The cash array
    int cash[2];
    //Take the inputs
    std::cin >> cash[0] >> cash[1];
    //Assigning
    int money = cash[0];
    int men   = cash[1];
    //Not enough money
    if(money < men)
    {
        std::cout << -1 << "\n";
    }
    //money is same as men
    else if(money == men)
    {
        std::cout << money << "\n";
    }
    //the fun stuff
    else
    {
        //Brute force algorithm starting with 2
        //eg: 10 -> {2,2,2,2,2}
        //if that doesn't get distributed evenly between the members
        //then we decrease twos by 1 and increment ones by 2
        //until it gets distributed evenly
       int two_note = floor(money/2);//GIV function
       int one_note = money % 2;

       while ((one_note+two_note)%men!=0)
       {
            two_note = two_note - 1;
            one_note = one_note + 2;

            if(two_note < 0)
            {
                std::cout << -1 << "\n";
                exit(0);
            }

       }
       
       std::cout << one_note+two_note << "\n";
    }
    return 0;
}