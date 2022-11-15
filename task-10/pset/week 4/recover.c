//Author : Arun Krishnan (AM.EN.U4CSE22004)

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

void checkArgumentCount(int argc);
void checkFileExists(FILE *file);
int isJPEG(BYTE buffer[]);

int main(int argc,char *argv[])
{
    checkArgumentCount(argc);
    FILE *row = fopen(argv[1],"r");
    checkFileExists(row);

    //alloc mem 
    BYTE buffer[BLOCK_SIZE];

    //filename buffer
    char filename[8];
    FILE *image;
    int counter =0;

    //After first JPEG image is found,all are adjacent
    while(fread(buffer,BLOCK_SIZE,1,row) == 1)
    {
        if(isJPEG(buffer)==1)
        {
            //Close the previous image unless its the first JPEG
            if(counter != 0)
            {
                fclose(image);
            }
            sprintf(filename,"%03i.jpg",counter++);
            image = fopen(filename,"w");
            fwrite(buffer,BLOCK_SIZE,1,image);
        }
        else if(counter>0)
        {
            fwrite(buffer,BLOCK_SIZE,1,image);
        }
    }


}

void checkArgumentCount(int argc)
{
    if(argc !=2)
    {
        printf("Usage ./recover image\n");
        exit(1);
    }
}

void checkFileExists(FILE *file)
{
    if(file == NULL)
    {
        printf("can't open file\n");
    }
}

int isJPEG(BYTE buffer[])
{
    if(buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]=0xff && (buffer[3]&0xf0)==0xe0)
    {
        return 1;
    }
    return 0;
}