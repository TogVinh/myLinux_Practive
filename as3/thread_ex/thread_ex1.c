#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *worker (void *data)
{
    char *name = (char*)data;
    int i =0;
    for ( ; i <120 ; i++)
    {
        usleep(50000);
        printf("thread  %s\n", name);
    }
    printf("thread %s done\n", name);
    return NULL;
}

int main()
{
    pthread_t th1, th2;
    pthread_create(&th1, NULL, worker, "X");
    pthread_create(&th2, NULL, worker, "Y");
    sleep(2);
    printf("exitting\n");
    return 0;
}