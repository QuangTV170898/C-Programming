/**
* \file
*         ring buff driver
* \author
*         Ngo Vu Truong Giang <truonggiangbkak58@gmail.com>
*/

#ifndef _RING_BUF_H_
#define _RING_BUF_H_

#include <stdint.h>
#include <stdlib.h>


#ifdef __cplusplus
 extern "C" {
#endif

 typedef struct
{
    volatile uint32_t head;                
    volatile uint32_t tail;                
    volatile uint32_t size;                
    volatile uint8_t *pt;  					
} RINGBUF;

int32_t RINGBUF_Init(RINGBUF *r, uint8_t* buf, uint32_t size);
int32_t RINGBUF_Put(RINGBUF *r, uint8_t c);
int32_t RINGBUF_Get(RINGBUF *r, uint8_t* c);
int32_t RINGBUF_GetFill(RINGBUF *r);
int32_t RINGBUF_Clear(RINGBUF *r, uint8_t num);
#ifdef __cplusplus
}
#endif
#endif
