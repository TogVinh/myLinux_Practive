#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

char memory[20000];
struct block
{
    size_t size;
    int Fr; /*this is used to know whether the block described
            by the metadata structure is free or not
            -> if free, set to 1*/
    struct block *next;
};

struct block *freeList = (void *)memory;

void initialize()
{
    freeList->size = 20000 - sizeof(struct block);
    freeList->Fr = 1;
    freeList->next = NULL;
}

void split(struct block *fitting, size_t size)
{
    struct block *new = (void *)((void *)fitting + size + sizeof(struct block));
    new->size = (fitting->size) - size - sizeof(struct block);
    new->Fr = 1;
    new->next = fitting->next;
    fitting->size = size;
    fitting->Fr = 0;
    fitting->next = new;
}

void *myMalloc(size_t Bytes)
{
    struct block *curr, *prev;
    void *result;
    if (!(freeList->size))
    {
        initialize();
        printf("Memory initialized\n");
    }

    curr = freeList;

    while ((((curr->size) < Bytes) || ((curr->Fr) == 0)) && (curr->next != NULL))
    {
        prev = curr;
        curr = curr->next;
        printf("One block checked\n");
    }

    if ((curr->size) == Bytes)
    {
        curr->Fr = 0;
        result = (void *)(++curr);
        printf("Exact fitting block allocated\n");
        return result;
    }
    else if ((curr->size) > (Bytes + sizeof(struct block)))
    {
        split(curr, Bytes);
        result = (void *)(++curr);
        printf("Fitting block allocated with a split \n");
        return result;
    }
    else
    {
        result = NULL;
        printf("No sufficient memory to allocate\n");
        return result;
    }
}

void merge()
{
    struct block *curr, *prev;
    curr = freeList;
    while ((curr->next) != NULL)
    {
        if (curr->Fr && curr->next->Fr)
        {
            curr->size += (curr->next->size) + sizeof(struct block);
            curr->next = curr->next->next;
        }
    }
}

void myFree(void *ptr)
{
    if (((void *)memory <= ptr) && ((void *)(memory + 20000)))
    {
        struct block *curr = ptr;
        --curr;
        curr->Fr = 1;
        merge();
    }
    else
    {
        printf("Let's provide a valid pointer allocated by malloc");
    }
}

void *realloc(void *ptr, unsigned long size)
{
    void *newPtr = malloc(size);
    memcpy(ptr, newPtr, ((struct block *)ptr)->size);
    free(ptr);
    return newPtr;
}

int main()
{
    int *a = (int *)myMalloc(100 * sizeof(int));
    if (a != NULL)
    {
        printf("Success\n");
    }
    myFree(a);
}