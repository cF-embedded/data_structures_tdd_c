#include "stack.h"

void stack_init(stack_s_t * stack)
{
    for(uint32_t i = 0; i < STACK_SIZE; i++)
    {
        stack->buffer[i] = 0;
    }

    stack->top = -1;
}

bool stack_is_empty(stack_s_t * stack)
{   
    if(stack->top == -1)
    {
        return true;
    }

    return false;
}

bool stack_push(stack_s_t * stack, item_t item)
{
    if(stack_is_full(stack))
    {
        return false;
    }

    stack->top += 1;
    stack->buffer[stack->top] = item;
    return true;
}

item_t stack_peek(stack_s_t * stack)
{
    if(stack_is_empty(stack))
    {
        return 0;
    }

    return stack->buffer[stack->top]; 
}

bool stack_pop(stack_s_t * stack)
{
    if(stack_is_empty(stack))
    {
        return false;
    }

    stack->buffer[stack->top] = 0;
    stack->top -= 1;
    return true;
}

bool stack_is_full(stack_s_t * stack)
{
    if(stack->top == (STACK_SIZE - 1))
    {
        return true;
    }

    return false;
}