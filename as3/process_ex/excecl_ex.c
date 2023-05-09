#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    printf("Run command <ls -lah> after2 second\n");
    //sleep(2);
    //execl("/bin/ls", "excecl", "-l", "-a", "-h", NULL);
    // printf("kill process \n");
    // kill(getpid(), SIGKILL);


    while (1)
    {
        /* code */
        printf("hello\n");
        sleep(2);
    }
    

    return 0;
}