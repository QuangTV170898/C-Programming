/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-22
 *
 * @copyright Copyright (c) 2023
 * target 22/02 - 26/02
 * ứng dụng
 * singly: 1 node sẽ bao gồm giá trị của node đó và địa chỉ của node tiếp theo HEAD->node_1->node_2->node_3->TAIL->NULL
 * doubly: 1 node sẽ bao gồm giá trị của node đó và địa chỉ của node tiếp theo và địa chỉ của node trước đó
 *     -->          -->         -->         -->         -->
 * HEAD     node_1      node_2      node_3      TAIL        NULL
 *     <--          <--         <--         <--         <--
 * khởi tạo danh sách.
 * tạo 1 node của danh sách.
 * thêm một phần tử đầu, cuối và sau một phần tử chỉ định cho danh sách.
 * duyệt phần tử trong danh sách.
 * tìm kiếm phần tử trong danh sách.
 * xóa phần tử đầu, cuối và một phần tử chỉ định của danh sách.
 * xóa tất cả các phần tử trong danh sách.
 */

#include <stdio.h>
#include <stdlib.h>

/* cấu trúc của 1 node */
typedef struct node_
{
    int val;
    struct node_ *pNext;
} node_t;

/* Cấu trúc của ds liên kết đơn */
typedef struct list_
{
    node_t *pHead; /* node quản lí đầu danh sách liên kết đơn */
    node_t *pTail; /* node quản lí cuối danh sách liên kết đơn*/
} list_t;

/* Khởi tạo cấu trúc của 1 danh sách liên kết đơn */
void create_list(list_t *list)
{
    list->pHead = NULL;
    list->pTail = NULL;
}

/* Khởi tạo 1 node cho danh sách liên kết đơn */
node_t *create_node(int val)
{
    node_t *temp;
    temp = (node_t*)malloc(sizeof(node_t)); // Cấp phát vùng nhớ cho note
    if (temp == NULL)
    {
        printf("Cấp phát vùng nhớ không thành công\n");
        return NULL;
    }
    temp->val = val;
    temp->pNext = NULL; /* node chưa được liên kết đến node nào trong danh sách liên kết đơn -> con trỏ sẽ trỏ đến NULL */
    
    return temp;
}

/* Thêm 1 node vào đầu danh sách đơn */
void add_node_head(list_t *list, node_t *p)
{
    if (list->pHead == NULL)
    {
        printf("list->pHead == NULL\n");
        list->pTail = list->pHead = p;
    }
    else
    {
        printf("list->pHead != NULL\n");
        p->pNext = list->pHead; /* cho con trỏ của node p liên kết đến node head */
        list->pHead = p;    /* cập nhật lại node head chính là node p */
    }

    printf("add note have value is: %d\n", p->val);
}

/* Thêm 1 node vào 1 vị trí bất kì trong ds liên kết */
void add_node_tail(list_t *list, node_t *p)
{
    if (list->pHead == NULL)
        list->pTail = list->pHead = p;
    else
    {
        p->pNext = p; /* cho con trỏ của node p liên kết đến node tail */
        list->pTail = p;    /* cập nhật lại node tail chính là node p */
    }
}

/* Xuất danh sách liên kết đơn */
int output_list(list_t list)
{
    node_t *note;
    for (note = list.pHead; note != NULL; note = note->pNext)
        printf("%d\n", note->val);
    printf("\n");
}

int main()
{
    int i, n;
    list_t list;
    node_t *pNote;

    printf("Hello linked list\n");

    create_list(&list);

    printf("Nhập số lượng node cần thêm: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        int x;
        printf("Nhập giá trị của note %d: ", i);
        scanf("%d", &x);
        pNote = create_node(x);
        printf("pNote is value: %d\n", pNote->val);

        add_node_head(&list, pNote);
    }

    printf("Xuất danh sách liên kết đơn\n");
    output_list(list);

    /* 
    * Khi delete 1 node chúng ta cần free vùng nhớ đó bởi vì đã dùng malloc 
    * Còn khi create 1 note thì chúng ta không được free bởi node đó đang được sử dụng trong list.
    */
    
    return 0;
}