#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t child;
    int status;
    int counter = 0;
    
    child = fork();
    if (child >= 0)
    {
        if (0 == child)
        {
            printf("child process terminatation\n");
        }
        else
        {
            /*se tao ra zombie*/
            //while(1);

            /*han che ra zombie*/
            //wait(&status);

        }
    }
    else{
        printf("forl Unsucessful\n");
    }
    return 0;
}