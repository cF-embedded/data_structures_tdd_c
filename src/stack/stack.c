#include "stack.h"

void stack_init(stack_s_t * stack)
{
    for(uint32_t i = 0; i < STACK_SIZE; i++)
    {
        stack->buffer[i] = 0;
    }

    stack->top = 0;
}

bool stack_is_empty(stack_s_t * stack)
{   
    if(stack->buffer[stack->top] != 0)
    {
        return false;
    }

    return true;
}

void stack_push(stack_s_t * stack, item_t item)
{
    stack->top += 1;
    stack->buffer[stack->top] = item;
}