
#include <stdio.h>
#include <stdlib.h>

// 声明节点
typedef struct Node
{
    int val;
    struct Node* next;
}Node;


// 尾插
Node* InsertAtTail(Node* head, int val)
{
    // 链表不为空时,先到达尾节点,然后直接追加
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    // 空链表直接插入即可
    if(NULL == head)
    {
        return newNode;
    }

    Node* tail = head;
    while(tail->next != NULL)
    {
        tail = tail->next; // 下一个节点
        // [2][4][6]
    }
    // 到达最后一个节点
    tail->next = newNode;
    return head;
    
}

void Print(Node* head)
{
    while(head)
    {
        printf("%d ", head->val);
        head = head->next; 
    }
    printf("\n");
}


Node* Reverse(Node* head)
{   
    if(NULL == head || NULL == head->next)
    {
        return head; // 返回最后一个节点
    }
    Node* newNode  = Reverse(head->next); // 递推
    // Node* p = head->next; // 当前节点中的next字段
    // p->next = head; // 建立当前节点链接前一个节点

    // 简写
    head->next->next = head;
    head->next = NULL; // 当前节点置为0
    return newNode;
}

int main()
{
    Node* head = NULL;
    printf("尾插: ");
    head = InsertAtTail(head, 1);
    head = InsertAtTail(head, 2);
    head = InsertAtTail(head, 3);
    Print(head);
    
    printf("反转: ");
    head = Reverse(head);
    Print(head);

    return 0;
}


/*
// 以下是力扣中提交的代码
struct ListNode* reverseList(struct ListNode* head) {

    // struct ListNode* prev = NULL; // 前一个节点地址
    // struct ListNode* next = NULL; // 记录下一个节点地址
    
    // while(head)
    // {
        
    //     next = head->next; // 记录下一个节点地址
    //     head->next = prev; // 当前节点next字段为prev
    //     prev = head; // 更新prev字段
    //     head = next; // 下一个节点
    // }
    // return prev;


    // 递归反转
    if(NULL == head || NULL == head->next) 
    {
        // 两个表达式位置不能反,如果head=NULL,先判断head->next就非法访问空指针了
        return head; // 返回最后一个节点
    }
    struct ListNode* newNode = reverseList(head->next);
    // struct ListNode* p = head->next;
    // p->next = head; // 指向前一个节点(或者说链接前一个节点)

    // 简写
    head->next->next = head;
    head->next = NULL; // 当前节点next字段为0
    // 返回尾节点作为新的头
    return newNode;
}
*/
