#include "cbuf.h"

void cbuf_init(cbuf_s_t * cbuf)
{
    cbuf->head = 0;
    cbuf->tail = 0;
}

bool cbuf_is_empty(cbuf_s_t * cbuf)
{
    return true;
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