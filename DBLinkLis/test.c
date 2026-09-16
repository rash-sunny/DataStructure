// 测试双链表的实现

#include "DBLinkList.h"



static void test01()
{
    // 空链表
    Node* head = NULL;

    // 头插
    printf("头插: ");
    head = InsertAtHead(head, 1);
    head = InsertAtHead(head, 2);
    head = InsertAtHead(head, 3);
    Print(head);
    printf("--------------------------------\n\n");

    printf("逆序输出: ");
    ReversePrint(head);
    printf("--------------------------------\n\n");


    printf("尾插: ");
    head = InsertAtTail(head, 0);
    head = InsertAtTail(head, -1);
    head = InsertAtTail(head, -2);
    head = InsertAtTail(head, -3);
    Print(head);
    printf("--------------------------------\n\n");

    printf("头删: ");
    head = PopHeadNode(head);
    head = PopHeadNode(head);
    head = PopHeadNode(head);
    // head = PopHeadNode(NULL);
    Print(head); // 0 -1 -2 -3
    printf("--------------------------------\n\n");


    printf("尾删: ");
    // head = PopTailNode(head);
    // head = PopTailNode(head);
    // head = PopTailNode(head);
    // head = PopTailNode(head);
    // head = PopTailNode(head);
    Print(head);
    printf("--------------------------------\n\n");

    
    printf("删除任意位置节点: ");  
    head = DelPosNode(head, 1);
    head = DelPosNode(head, 3);
    head = DelPosNode(head, 2);
    head = DelPosNode(head, 1);
    head = DelPosNode(NULL, 1);
    // head = DelPosNode(head, 1);
    // head = DelPosNode(NULL, 1);
    // head = DelPosNode(head, 1);
    // head = DelPosNode(head, 2);
    // head = DelPosNode(head, 1);
    Print(head); // -1 -3
    printf("逆序输出: "); // -3 -1 
    ReversePrint(head);
    printf("--------------------------------\n\n");

    printf("任意位置插入节点: ");
    head = InsertPosNode(NULL,1,0); // 空链表
    head = InsertPosNode(head,1,1);
    head = InsertPosNode(head,2,2);
    head = InsertPosNode(head,3,3); 
    head = InsertPosNode(head,5,-1); 
    head = InsertPosNode(head,6,-2); 
 
    Print(head);
    printf("--------------------------------\n\n");
    printf("逆序输出: "); // -2 -1 0 3 2 1
    ReversePrint(head);
    

}



static void test02()
{
    Node* head = NULL;

    printf("头插: ");
    head = InsertAtHead(NULL,1);
    head = InsertAtHead(head,2);
    head = InsertAtHead(head,3);
    head = InsertAtHead(head,4);
    Print(head); // 4 3 2 1
    printf("--------------------------\n");

    printf("尾插: ");
    head = InsertAtTail(head, 0);
    head = InsertAtTail(head, 1);
    head = InsertAtTail(head, 2);
    head = InsertAtTail(head, 3);
    head = InsertAtTail(head, 4);
    Print(head); // 4 3 2 1 0 1 2 3 4
    printf("--------------------------\n");


    printf("头删: ");
    head = PopHeadNode(head);
    head = PopHeadNode(head);
    head = PopHeadNode(head);
    head = PopHeadNode(head);
    // head = PopHeadNode(NULL);
    Print(head); // 0 1 2 3 4
    printf("--------------------------\n");


    printf("尾删: ");
    head = PopTailNode(head);
    head = PopTailNode(head);
    head = PopTailNode(head);
    head = PopTailNode(head);
    head = PopTailNode(head);
    // head = PopTailNode(head);
    Print(head); // NULL 
    printf("--------------------------\n");


    printf("任意位置插入: ");
    head = InsertPosNode(NULL,1,2);
    head = InsertPosNode(head,1,0);
    // head = InsertPosNode(head,3,4);
    // head = InsertPosNode(head,4,6);
    // head = InsertPosNode(head,6,7); // 插入无效位置
    Print(head); // 0 2 4 6
    printf("--------------------------\n");


    printf("删除任意位置: ");
    head = DelPosNode(head, 2);
    head = DelPosNode(head, 1);
    Print(head); 
    printf("--------------------------\n");

    // 逆序输出
    // head = DelPosNode(head,3);
    // head = DelPosNode(head,1);
    // printf("逆序输出: ");
    // ReversePrint(head);

    printf("反转前: ");
    head = InsertAtTail(head, 1);
    head = InsertAtTail(head, 2);
    head = InsertAtTail(head, 3);
    head = InsertAtTail(head, 2);
    head = InsertAtTail(head, 1);
    Print(head); // 1 2 3 2 1
    
    printf("反转后: ");
    head = Reverse(head);
    Print(head); // 1 2 3 2 1

    // 测试能否逆序输出
    printf("逆序输出: ");
    ReversePrint(head); // 1 2 3 2 1 
    
}



int main()
{
    // test01();
    test02();
    return 0;
}