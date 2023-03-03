#ifndef __COMMON_H__
#define __COMMON_H__

#define clear() printf("\033[H\033[J")

typedef struct node_t
{
    int val;
    struct node_t *pNext;
} node_ctx;

typedef struct list_t
{
    node_ctx *pHead;
    node_ctx *pTail;
} list_ctx;

node_ctx *node_create(int x);
void list_create(list_ctx *ctx);

void list_add_head(node_ctx *node, list_ctx *ctx);
void list_add_tail(node_ctx *node, list_ctx *ctx);

void list_out(list_ctx ctx);
int list_search_max(list_ctx ctx);

#endif // __COMMON_H__

