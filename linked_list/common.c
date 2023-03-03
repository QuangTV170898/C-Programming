#include <stdio.h>
#include <stdlib.h>
#include "common.h"

node_ctx *node_create(int x)
{
    node_ctx *ret;
    ret = (node_ctx*)malloc(sizeof(node_ctx));
    if (ret == NULL){
        ("[Create]Failed to allocate node context!\n");
        return ret;
    }
    ret->val = x;
    ret->pNext = NULL;
    return ret;
}

void list_create(list_ctx *ctx)
{
    ctx->pHead = NULL;
    ctx->pTail = NULL;
}

void list_add_head(node_ctx *node, list_ctx *ctx){
    if (ctx->pHead == NULL)
        ctx->pHead = ctx->pTail = node;
    else{
        node->pNext = ctx->pHead;
        ctx->pHead = node;
    }
}
void list_add_tail(node_ctx *node, list_ctx *ctx)
{
    if (ctx->pHead == NULL)
        ctx->pHead = ctx->pTail = node;
    else{
        ctx->pTail->pNext = node;
        ctx->pTail = node;
    }
}

int list_search_max(list_ctx ctx)
{
    node_ctx *node;
    int max = ctx.pHead->val;
    for (node = ctx.pHead->pNext; node != NULL; node = node->pNext)
    {
        if (max < node->val)
            max = node->val;
    }

    return max;   
}
int list_search_min(list_ctx ctx)
{}

void list_out(list_ctx ctx){
    node_ctx *node;
    for(node= ctx.pHead; node != NULL; node = node->pNext)
        printf ("%d\t", node->val);
    printf("\n");
}