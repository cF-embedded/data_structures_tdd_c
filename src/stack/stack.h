#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct 
{
    uint32_t buffer[32];
    uint8_t top;
} stack_s_t; 

void stack_init(stack_s_t *);

bool stack_is_empty(stack_s_t *);