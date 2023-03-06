#include <stdio.h>

#include "ringbuffer.h"

int rb_init(rb_context *ctx, uint8_t *buf, uint32_t size)
{
    if (ctx == NULL || buf == NULL || size < 2)
        return -1;
    
    ctx->data = buf;
    ctx->len = size;
    ctx->head = 0;
    ctx->tail = 0;
    return 0;
}



int rb_push(rb_context *ctx, uint8_t data)
{

}