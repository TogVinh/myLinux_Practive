#include<stdio.h>
#include<stddef.h>

char memory[20000];
struct block
{
    size_t size;
    int Fr; /*this is used to know whether the block described
            by the metadata structure is free or not
            -> if free, set to 1*/
    struct block *next; 
}

struct block *freeList = (void*)memory;

void initialize()
{
    freeList->size = 20000 - sizeof(struct block);
    freeList->Fr = 1;
    freeList->next = NULL;
}

void split( struct block *fitting, size_t size )
{
    struct block *new = (void*)( (void*)fitting + size + sizeof(struct block) );
    new->size = (fitting->size) - size - sizeof(struct block)
    new->free = 1;
    new->next = fitting->next;
    fitting->size = size;
    fitting->free = 0;
    fitting->next = new;
}

void myMalloc(size_t Bytes)
{
    struct block *curr, *prev;
    void *result;
    if( !(freeList->size) )
    {
        initialize();
        printf("Memory initialized\n");
    }

    curr = freeList;

    while( (((curr->size)<Bytes) ||((curr->free)==0)) && (curr->next!=NULL))
    {
        prev=curr;
        curr=curr->next;
        printf("One block checked\n");
    }

    if((curr->size) == Bytes)
    {
        curr->Fr = 0;
        result = (void*)(++curr);
        printf("Exact fitting block allocated\n");
        return result;
    }
    else if( (curr->size) > (Bytes + sizeof(struct block)) )
    {
        split(curr, Bytes);
        result = (void*)(++curr);
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
    while( (curr->next)!= NULL )
    {
        if (curr->Fr && curr->next->Fr)
        {
            curr->size += (curr->next->size) + sizeof(struct block);
            curr->next = curr->next->next;
        }
    }
}