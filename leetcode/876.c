 #include <stdio.h>
 #include <stdlib.h>
 
typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* InsertAtTail(Node* head, int val)
{
    // 创建节点
    Node* node = (Node*)malloc(sizeof(Node));
    
    node->data = val;
    node->next = NULL;

    // 空链表
    if(NULL == head)
    {
        return node;
    }

    // 非空链
    // 找尾节点 [1][2][3]
    Node* tail = head; 
    while(tail->next != NULL)
    {
        tail = tail->next;
    }
    
    // 到达尾节点
    tail->next = node; 
    return head;

}

void Print(Node* head)
{
    //[1][2][3]
    while(head) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}



Node* middleNode(Node* head) 
{
//  typedef struct ListNode Node;
    Node* fast = head; // 快指针
    Node* slow = head; // 慢指针

    while(fast && fast->next != NULL) 
    {
        slow = slow ->next;
        fast = fast ->next->next;
    }
    return slow;


}

// 循环条件不可以交换，因为：当链表节点个数为偶数时,fast指向为空


int main()
{
    Node* head = NULL;

    head = InsertAtTail(head, 1);
    head = InsertAtTail(head, 2);
    head = InsertAtTail(head, 3);
    head = InsertAtTail(head, 4);
    head = InsertAtTail(head, 5);
    head = InsertAtTail(head, 6);
    head = middleNode(head);
    Print(head);

    return 0;
}


/*
    提交的代码
    struct ListNode* middleNode(struct ListNode* head) {
    typedef struct ListNode Node;

    Node* fast = head; // 快指针
    Node* slow = head; // 慢指针

    while(fast && fast->next != NULL)
    {
        slow = slow ->next;
        fast = fast ->next->next;
    }
    return slow;
    }

*/