#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define CBUF_SIZE 32

typedef uint32_t buffer_t;
typedef size_t index_t;

/* if buffer size changes, item must also change */
typedef buffer_t item_t;

typedef struct 
{
    buffer_t buffer[CBUF_SIZE];
    index_t head;
    index_t tail;
} cbuf_s_t; 

void cbuf_init(cbuf_s_t *);

bool cbuf_is_empty(cbuf_s_t *);