#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *pFile = NULL;
    char fileName[255] = {'0'};
    char writeFile[255];

    // in thong bao
    printf("Program name is: %s\n", argv[0]);

    if (argc < 2)
    {
        printf("No argument passed through command line.\n");
    }
    else
    {
        //printf("path file is: %s\n", argv[1]);
        //printf("path file is : %s\n",fileName);


        strcpy(fileName,argv[1]);

        pFile = fopen(fileName, "w+");
        if (pFile == NULL)
        {
            printf("Unsucessfully \n");
            exit(1);
        }

        // Input string to file
        printf("Input your string : \n ")    ;
        fflush(stdin);
        fgets(writeFile, 255, stdin );
        // write to file
        fputs(writeFile, pFile);
        printf("write to file is done !!\n");

    }


    fclose(pFile);
    return 0;
}