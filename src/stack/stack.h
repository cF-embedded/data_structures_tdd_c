#pragma once

#include <stdint.h>
#include <stdbool.h>

#define STACK_SIZE 32

typedef uint32_t buffer_t;
typedef int16_t top_t;

/* if buffer size changes, item must also change */
typedef buffer_t item_t;

typedef struct 
{
    buffer_t buffer[STACK_SIZE];
    top_t top;
} stack_s_t; 

void stack_init(stack_s_t *);

bool stack_is_empty(stack_s_t *);

bool stack_push(stack_s_t *, item_t);

item_t stack_peek(stack_s_t *);

bool stack_pop(stack_s_t *);

bool stack_is_full(stack_s_t *);