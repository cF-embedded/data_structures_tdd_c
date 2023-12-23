#pragma once

#include <stdint.h>
#include <stdbool.h>

#define STACK_SIZE 32

typedef uint32_t buffor_t;
typedef uint8_t top_t;

/* if buffer size changes, item must also change*/
typedef buffor_t item_t;

typedef struct 
{
    buffor_t buffer[STACK_SIZE];
    top_t top;
} stack_s_t; 

void stack_init(stack_s_t *);

bool stack_is_empty(stack_s_t *);

void stack_push(stack_s_t *, item_t);