#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

pthread_t id1, id2;

typedef struct
{
    char name[30];
    char msg[30];
} data_t;

void *thr_handle(void *args)
{
    pthread_t tid = pthread_self();
    data_t *data = (data_t *)args;

    if (pthread_equal(tid, id1))
    {
        printf("thread ID 1\n");
    }
    else
    {
        printf("thread ID 2 \n");
        printf("hello %s, welcom to join %s\n", data->name, data->msg);
    }
}

void thr_handle2(void *args)
{
    printf("hi i am thread hanle 2\n");
}

int main()
{
    int ret;
    data_t data = {0};

    strncpy(data.name, "someOne1", sizeof(data.name));
    strncpy(data.msg, "thread program", sizeof(data.msg));

    if (ret = pthread_create(&id1, NULL, &thr_handle, NULL))
    {
        printf("pthread number %d\n", ret);
        return -1;
    }

    sleep(5);
    if (ret = pthread_create(&id2, NULL, &thr_handle, &data))
    {
        printf("pthread_create %d\n", ret);
        return -1;
    }

    sleep(5);

    return 0;
}