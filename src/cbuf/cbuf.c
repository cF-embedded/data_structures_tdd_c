#include "cbuf.h"

void cbuf_init(cbuf_s_t * cbuf)
{
    cbuf->head = 0;
    cbuf->tail = 0;
}

bool cbuf_is_empty(cbuf_s_t * cbuf)
{
    if(cbuf->head != cbuf->tail)
    {
        return false;
    }
    
    return true;
}

bool cbuf_is_full(cbuf_s_t * cbuf)
{
    if(cbuf->tail > (cbuf->head + (CBUF_SIZE - 1)))
    {
        return true;
    }
    
    return false;
}

bool cbuf_push(cbuf_s_t * cbuf, item_t item)
{
    if(cbuf_is_full(cbuf))
    {
        return false;
    }

    cbuf->buffer[cbuf->tail] = item;
    cbuf->tail++;

    return true;
}

item_t cbuf_pop(cbuf_s_t * cbuf)
{
    item_t actual_item = 0;

    if (cbuf_is_empty(cbuf))
    {
        return actual_item;
    } 

    actual_item = cbuf->buffer[cbuf->head];
    cbuf->head++;
    
    return actual_item;
}

#ifdef UNIT_TESTING
index_t cbuf_get_head(const cbuf_s_t* cbuf) 
{
    return cbuf->head;
}

index_t cbuf_get_tail(const cbuf_s_t* cbuf) 
{
    return cbuf->tail;
}
#endif