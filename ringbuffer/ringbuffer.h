#ifndef __RING_BUFFER_H__
#define __RING_BUFFER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>



typedef struct rb_t
{
    uint32_t head;
    uint32_t tail;
    uint32_t len;
    uint8_t const *data; /* gia tri dc tro den co the thay doi nhung con tro thi khong doi */
} rb_context;

int rb_init(rb_context *ctx, uint8_t *buf, uint32_t size);
int rb_push(rb_context *ctx, uint8_t data);
int rb_pop(rb_context *ctx, uint8_t *data);

#ifdef __cplusplus
}
#endif
#endif // __RING_BUFFER_H__