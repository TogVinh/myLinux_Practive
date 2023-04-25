#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char *argv[])
{
    pid_t child_pid;
    int status, rv;


    child_pid = fork();
    if (child_pid >= 0 )
    {
        if (0 == child_pid) //process con
        {
            printf("--------------------\n");
            printf("child process -- PID : %d\n", getpid());
            exit(0);

        }
        else // process cha
        {
            rv = wait(&status);
            if (rv == -1)
            {
                printf("wait() Unsuccesful\n");
            }
            
            printf("parent process -- child's PID : %d\n", rv);

            if (WIFEXITED(status))
            {
                printf("normal termination, status = %d\n", WEXITSTATUS(status));

            }
            
            else if (WIFSIGNALED(status))
            {
                printf("kill by signal, value = %d\n", WTERMSIG(status));
            }

        }
    }
    else
    {
        printf("fork() unsuccessfully \n");
    }

    return 0;
}