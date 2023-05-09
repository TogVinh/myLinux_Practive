#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

pthread_t id1, id2 , id3;

typedef struct
{
    char name[30];
    char msg[30];
}thr_data;

void *thr_handle1(void *args)
{
    thr_data *thr = (thr_data*)args;
    sleep(1);
    printf("hello %s \n",thr->name);
    printf("thread 1 handler\n");

    pthread_exit(NULL); //exit

}

void *thr_handle2(void *args)
{
    sleep(2);
    exit(1);
    while(1)
    {
        printf("thread 2 handler\n");
        sleep(1);
    };

    pthread_exit(NULL);
}

void *thr_handle3 (void *args)
{
    pthread_detach(pthread_self());
    //sleep(2);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    int ret;
    int counter = 0;
    int retval;
    thr_data data;

    strncpy(data.name, "someone", sizeof(data.name));
    strncpy(data.msg, "thread programming\n", sizeof(data.msg));

    if (ret = pthread_create(&id1, NULL, &thr_handle1, &data))
    {
        printf("pthread_create error number is %d\n", ret);
        return -1;
    }

    if(ret = pthread_create(&id2, NULL, &thr_handle2,NULL))
    {
        printf("pthread_create error number is %d\n", ret);
        return -1;
    }

    while(1);

    sleep(5);
    pthread_cancel(id2);
    pthread_join(id2, NULL);
    printf("thread ID-2 termination\n");

    while(1)
    {
        if (ret = pthread_create(&id3, NULL, &thr_handle3, NULL))
        {
            printf("thread create error number = %d\n", ret);
            break;
        }
        counter++;
        //pthread_join(id3, NULL);
        if (counter % 1000 == 0)
        {
            printf("thread creadted: %d\n", counter);
        }
        
    }
    
    sleep(5);
    // pthread_cancel(id2);
    // sleep(100);

    return 0;
}