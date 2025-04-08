#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void initStack(Stack *ps)
{
    ps->tos=0;

}

void push(Stack *ps,int data)
{
    // stack[tos]=data;
    // ++tos;
    // s.array[s.tos]=data;
    // ++s.tos;
    
    // ps->array[ps->tos]=data;
    // ++ps->tos;

    if (ps->tos == STACKSIZE)
    {
        fprintf(stderr,"stack is full.\n");
        exit(1);
    }

    (*ps).array[(*ps).tos]=data;
    ++(*ps).tos;
}
int pop(Stack *ps)
{
    // --tos;
    // return stack[tos];

    // --ps->tos;
    // return ps->array[ps->tos];

    if (ps->tos == 0)
    {
        fprintf(stderr,"stack is empty.\n");
        exit(2);
    }

    --(*ps).tos;
    return (*ps).array[(*ps).tos];
}