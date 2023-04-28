#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h> 

void timer_callback(int signum)
{
    time_t now = time(NULL);
    printf("Signal %d caught on %li", signum, now);
}

int main()
{
    signal(SIGALRM, timer_callback);
    alarm(5);
    sleep(3);
    return 0;
}