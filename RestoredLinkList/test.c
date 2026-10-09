#include "LinkList.h"

static void test01()
{
    Node* head = NULL;
    // 头插
    // InsertFront(&head, 6);
    // InsertFront(&head, 3);
    // // InsertFront(NULL, 1);
    // printf("头插: ");
    // Print(head);

    // InsertTail(&head, 4);
    // InsertTail(&head, 3);
    // InsertTail(NULL, 3);
    // printf("尾插: ");
    // Print(head);

    // DelFront(NULL);
    // // DelFront(&head);
    // printf("头删: ");
    // Print(head);

    // DelTail(&head);
    // DelTail(NULL);
    // DelTail(&head);
    // DelTail(&head);
    // printf("尾删: ");
    // Print(head);



    // 任意位置插入节点
    // InsertPosNode(&head, 7, 0);
    // InsertPosNode(&head, 4, 2);
    // InsertPosNode(&head, 2, 1);
    // InsertPosNode(&head, 9, 4);
    // printf("任意位置插入节点: ");
    // Print(head); // 2 7 9 4 


    // 删除任意位置节点
    InsertTail(&head, 2);
    InsertTail(&head, 4);
    InsertTail(&head, 6);
    InsertTail(&head, 5);
    printf("删除前: "); // 2 4 6 5 
    Print(head);

    DelPosNode(&head, 1);
    DelPosNode(&head, 3);
    DelPosNode(&head, 2);
    // DelPosNode(&head, 1);
    // DelPosNode(&head, 1);
    // DelPosNode(NULL, 1);
    printf("删除后: ");
    Print(head);


    // 释放链表
    DestroyList(&head);
}


int main()
{
    test01();
    return 0;
}

// 复习链表

