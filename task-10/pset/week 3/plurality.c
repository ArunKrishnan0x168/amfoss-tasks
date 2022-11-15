//Author : Arun Krishnan (AM.EN.U4CSE22004)

#include <stdio.h>
#include <string>

#define MAX 9

//struct to store candidates name and votes
typedef struct plurality
{
    string name;
    int votes;
};
candidate;

// Candidates array
candidate candidates[MAX];

//Number of candidates
int candidate_count;

bool vote(string name);
void print_winner(void);

int main(int argc,string argv[])
{
    if(argc < 2)
    {
        printf("Error\n")
        return 1;
    }

    candidate_count = argc - 1;//we do -1 coz the name of the function is not an argument

    if(candidate_count > MAX)
    {
        printf("Greater than 9 \n");
        return 2;
    }
    //Initialzing the struct
    for(int i=0;i<candidate_count;i++)
    {
        candidates[i].name = argv[i+1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters\n");

    //loop over all the voters
    for(int i=0;i<voter_count;i++)
    {
        string name  = get_string("Vote: ");

        //invalid vote
        if(!vote(name))
        {
            printf("Invalid Vote\n");
        }
    }
    //winner
    print_winner();
    
    return 0;
}

//update vote

bool vote(string name)
{
    for (int i= 0;i<candidate_count;i++)
    {
        if (strcmp(name,candidates[i].name)==0)
        {
            candidates[i].votes++;
            return true
        }
    }
    return false;
}

//print winner

void print_winner()
{
    int max_votes = candidates[0].votes;
    for(int i=0;i<candidate_count;i++)
    {
        if(candidates[i].votes > max_votes)
        {
            max_votes candidates[i].votes;
        }
    }
    for(int i=0;i<candidate_count;i++)
    {
        if(candidates[i].votes == max_votes)
        {
            printf("%s\n",candidates[i].name);
        }
    }
}

