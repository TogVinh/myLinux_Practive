#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void func(int signum)
{
    printf("i am in func \n");
    wait(NULL);
}

int main(int argc, char *argv[])
{
    pid_t child;
    
    child = fork();

    if (child >= 0)
    {
        if (0 == child)
        {
            printf("child process\n");
            while(1);
        }
        else
        {
            /*se tao ra zombie*/
            signal(SIGCHLD, func);
            printf("Parent\n");
            while(1);

            /*han che ra zombie*/
            //wait(&status);

        }
    }
    else{
        printf("fork Unsucessful\n");
    }
    return 0;
}