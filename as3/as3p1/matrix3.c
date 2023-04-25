#include <stdio.h>
#include <pthread.h>

int not ;

int main()
{
    long int i,j;
    pthread_t tid[10];

    matrix_read();
    printf("enter no threads : ");
    scanf("%d",&not);
    
    //create threads
    for (i = 0 ; i < not : i++
    {
        pthread_create(&tid[i], NULL, multiplication, (void*)i)
    }
}