/* A C program that does not terminate when Ctrl+C is pressed */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/* Signal Handler for SIGINT */
void sigintHandler(int sig_num)
{
	signal(SIGINT, sigintHandler);
	printf("\nCannot be terminated using Ctrl+C");
	printf("\nContinue program !!\n");
    fflush(stdout);
}

int main ()
{
    int a = 0;
	signal(SIGINT, sigintHandler);

	/* Infinite loop */
	while(1)
	{
        printf("%d\n",a);
        a++;
        sleep(2);
	}
	return 0;
}
