#include <stdio.h>     /* standard I/O functions                         */
#include <unistd.h>    /* standard unix functions, like getpid()         */
#include <signal.h>    /* signal name macros, and the signal() prototype */
#include <stdlib.h>
/* first, define the Ctrl-C counter, initialize it with zero. */
int ctrl_c_count = 0;
#define	CTRL_C_THRESHOLD	5

/* the Ctrl-C signal handler */
void catch_int(int sig_num)
{
    sigset_t mask_set;	/* used to set a signal masking set. */
    sigset_t old_set;	/* used to store the old mask set.   */

    /* re-set the signal handler again to catch_int, for next time */
    signal(SIGINT, catch_int);
    /* mask any further signals while we're inside the handler. */
    sigfillset(&mask_set);
    sigprocmask(SIG_SETMASK, &mask_set, &old_set);
    
    /* increase count, and check if threshold was reached */
    ctrl_c_count++;
    printf("The number of ^C's is %d\n",ctrl_c_count);
    if (ctrl_c_count >= CTRL_C_THRESHOLD) {
	char answer[80];

	/* prompt the user to tell us if to really exit or not */
	printf("\nRealy Exit? [y/N]: ");
	fflush(stdout);
	fgets(answer,80,stdin);
	if (answer[0] == 'y' || answer[0] == 'Y') {
	    printf("\nExiting...\n");
	    fflush(stdout);
	    exit(0);
	}
	else {
	    printf("\nContinuing\n");
	    fflush(stdout);
	    /* reset Ctrl-C counter */
	    ctrl_c_count = 0;
	}
    }
    /* restore the old signal mask */
    sigprocmask(SIG_SETMASK, &old_set, NULL);
}

/* the Ctrl-Z signal handler */
void catch_suspend(int sig_num)
{
    sigset_t mask_set;	/* used to set a signal masking set. */
    sigset_t old_set;	/* used to store the old mask set.   */

    /* re-set the signal handler again to catch_suspend, for next time */
    signal(SIGTSTP, catch_suspend);
    /* mask any further signals while we're inside the handler. */
    sigfillset(&mask_set);
    sigprocmask(SIG_SETMASK, &mask_set, &old_set);

    /* print the current Ctrl-C counter */
    printf("\n\nSo far, '%d' Ctrl-C presses were counted\n\n", ctrl_c_count);
    fflush(stdout);

    /* restore the old signal mask */
    sigprocmask(SIG_SETMASK, &old_set, NULL);
}

int main(int argc, char* argv[])
{
    /* set the Ctrl-C and Ctrl-Z signal handlers */
    signal(SIGINT, catch_int);
    signal(SIGTSTP, catch_suspend);

    /* enter an infinite loop of waiting for signals */
    for ( ;; )
	pause();

    return 0;
}
