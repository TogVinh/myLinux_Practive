#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_handl(int signum)
{
    int num;
    printf("\ninput a number : ");
    scanf("%d", &num);
}

int main()
{
    signal(SIGINT, sig_handl);
    int i = 0;
    while(1)
    {
        fflush(stdout);
        printf("%d ",i);
        i++;

        sleep(2);
    }

    return 0;
}