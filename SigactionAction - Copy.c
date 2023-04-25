#include <signal.h>
#include <stdio.h>
#include <string.h>

void sigint_handler (int signal)
{
    int num;
    if (signal == SIGINT)
    {
        printf("Intercepted SIGINT \n");
        printf("input a number : ");
        scanf("%d", &num);
        return;
    }
}

void set_signal_action()
{
    struct sigaction act;
    bzero(&act, sizeof(act));
    act.sa_handler = &sigint_handler;
    sigaction(SIGINT, &act, NULL);
}

int main()
{
    set_signal_action();
    while (1)
    {
        continue;
        printf("in\n");
    }
    return 0;
}
