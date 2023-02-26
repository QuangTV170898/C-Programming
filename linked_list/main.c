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
#include <stdbool.h>

#define clear() printf("\033[H\033[J")

/* cấu trúc của 1 node */
typedef struct node_
{
    int val;             /* giá trị của 1 node */
    struct node_ *pNext; /* con trỏ dùng để liên kết giữa các node với nhau */
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
    /* cho 2 node đầu và cuối trỏ đến con trỏ null */
    list->pHead = NULL;
    list->pTail = NULL;
}

/* Khởi tạo 1 node cho danh sách liên kết đơn */
node_t *create_node(int val)
{
    node_t *temp;
    temp = (node_t *)malloc(sizeof(node_t)); // Cấp phát vùng nhớ cho node
    if (temp == NULL)
    {
        printf("Cấp phát vùng nhớ không thành công\n");
        return NULL;
    }
    temp->val = val;    /* gán giá trị val cho node */
    temp->pNext = NULL; /* node chưa được liên kết đến node nào trong danh sách liên kết đơn -> con trỏ sẽ trỏ đến NULL */

    return temp;
}

/* Thêm 1 node vào đầu danh sách đơn */
void add_node_head(list_t *list, node_t *p)
{
    /* danh sách rỗng */
    if (list->pHead == NULL)
    {
        printf("list->pHead == NULL\n");
        list->pTail = list->pHead = p;
    }
    else /* danh sách đã tồn tại phần tử */
    {
        printf("list->pHead != NULL\n");
        p->pNext = list->pHead; /* cho con trỏ của node p liên kết đến node head */
        list->pHead = p;        /* cập nhật lại node head chính là node p */
    }

    printf("add node have value is: %d\n", p->val);
}

/* Thêm 1 node vào 1 vị trí bất kì trong ds liên kết */
void add_node_tail(list_t *list, node_t *p)
{
    if (list->pHead == NULL)
        list->pTail = list->pHead = p;
    else
    {
        list->pTail->pNext = p; /* cho con trỏ của node p liên kết đến node tail */
        list->pTail = p;        /* cập nhật lại node tail chính là node p */
    }
}

/* Xuất danh sách liên kết đơn */
int output_list(list_t list)
{
    node_t *node;
    for (node = list.pHead; node != NULL; node = node->pNext)
        printf("%d\n", node->val);
    printf("\n");
}
/**
 * @brief Thêm 1 node p sau 1 node q trong danh sách liên kết.
 *
 * @return int
 *
 * Nhập danh sách liên kết đơn các số nguyên.
 * Khai báo cấu trúc của danh sách liên kết.
 * Khai báo cấu trúc của 1 node trong danh sách liên kết.
 * Khởi tạo cấu trúc danh sách đơn.
 * Khởi tạo 1 node trong danh sách liên kết đơn.
 */
void menu_conf()
{
    char c;
    int val;
    printf("i. node input list\n");
    printf("o. output list \n");
    printf("e. exit\n");

    while (true)
    {
        printf("Enter your choice :  ");
        scanf(" %c", &c);
        switch (c)
        {
        case 'i':
        {
            printf("enter value node: ");
            scanf("%d", &val);
            break;
        }

        case 'o':
        {
            printf("o. output linked list\n");
            break;
        }
        case 'e':
        {
            printf("e. exit menu\n");
            break;
        }
        default:
            printf("Not support this option %c\n", c);
            break;
        }
        char c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }
}

int main()
{
    int i, n;
    list_t list;
    node_t *pnode;

    menu_conf();

    printf("Hello linked list\n");

    create_list(&list);

    printf("Nhập số lượng node cần thêm: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        int x;
        printf("Nhập giá trị của node %d: ", i);
        scanf("%d", &x);
        pnode = create_node(x);
        printf("pnode is value: %d\n", pnode->val);

        add_node_head(&list, pnode);
    }

    printf("Xuất danh sách liên kết đơn\n");
    output_list(list);

    /*
     * Khi delete 1 node chúng ta cần free vùng nhớ đó bởi vì đã dùng malloc
     * Còn khi create 1 node thì chúng ta không được free bởi node đó đang được sử dụng trong list.
     */

    return 0;
}