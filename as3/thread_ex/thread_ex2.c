#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

pthread_t id1, id2;

typedef struct
{
    char name[30];
    char msg[30];
}thr_data;

void *thr_handle(void *args)
{
    pthread_t tid = pthread_self();
    thr_data *data = (thr_data*)args;

    if (pthread_equal(tid, id1))
    {
        printf("this is ID-1\n");
    }
    else
    {
        printf("This is ID-2\n");
        printf("Welcome %s to join %s\n",data->name, data->msg);
    }
}

void *thr_handle2 (void *args)
{
    printf("In the Handle 2\n");
}

int main(int argc, char *argv[])
{
    int ret;
    thr_data data;

    strncpy(data.name, "number-1", sizeof(data.name));
    strncpy(data.msg, "THREAD Code\n", sizeof(data.msg));

    if(ret = pthread_create(&id1, NULL, &thr_handle, NULL))
    {
        printf("pthread_create error number = %d\n", ret);
        return -1;
    }

    sleep(2);

    if (ret = pthread_create(&id2, NULL, &thr_handle, &data))
    {
        printf("pthread_create(error number = %d\n", ret);
        return -1;
    }

    sleep(5);

    return 0;

}
