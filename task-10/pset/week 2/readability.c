//Author : Arun Krishnan (AM.EN.U4CSE22004)

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#Function declaration
int getNumLetters(string text);
int getNumSentences(string text);
int getNumWords(string text);
int getGradeLevel(int numLetters, int numSentences, int numWords);

void printGradeLevel(int gradeLevel);

int main()
{
    string text = get_string("Text: ");

    int numLetters = getNumLetters(text);

    int numSentences = getNumSentences(text);

    int numWords = getNumWords(text);

    int gradeLevel = getGradeLevel(numLetters,numSentences,numWords);

    printGradeLevel(gradeLevel);
}

int getNumLetters(string text)
{
    int numLetters = 0;
    for (int i=0;i<strlen(text);i++)
    {
        //Check whether the number is an alphabet
        if(isalpha(text[i]))
        {
            numLetters += 1;
        }
    }
    return numLetters;
}

int getNumSentences(string text)
{
    int numSentences = 0;
    for (int i =0;i<strlen(text);i++)
    {
        if(text[i]=="."||text[i]=="!"||text[i]=="?")
        {
            numSentences += 1;
        }
    }
    return numSentences;
}

int getNumWords(string text)
{
    int numWords = 0;
    for(int i=0;i<strlen(text);i++)
    {
        if(text[i]==" ")
        {
            numWords += 1;
        }
    }
    return numWords;
}

int getGradeLevel(int numLetters, int numSentences, int numWords)
{
    float S = (numSentences / (float)numWords)*100;

    float L = (numWords / (float)numWords)*100;

    return round(0.0588 * L - 0.296*S - 15.8);
}

void printGradeLevel(int gradeLevel)
{
    if(gradeLevel <= 1)
    {
        printf("Lower than Grade 1\n");
    }
    else if(gradeLevel >= 16)
    {
        printf("Higher than Grade 16\n");
    }
    else
    {
        printf("Grade %i\n",gradeLevel);
    }
}