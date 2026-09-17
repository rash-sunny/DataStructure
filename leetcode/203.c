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



Node* Remove(Node* head, int val)
{
    // [1][2][3]
    Node* cur = head;
    Node* prev = NULL;

    // 当前节点是否删除
    while(cur != NULL && cur->data == val)
    {   
        cur = head->next; // 下一个节点
        free(head); 
        head = cur; // 成为新头
    }

    if(NULL == head)
    {
        return head;
    }

    while(cur)
    {
        
        // 判断是否删除节点
        if(cur->data == val)
        {
            // 前一个节点链接后一个节点
            prev->next = cur->next;
            // 删除节点
            free(cur);
            cur = prev; // 回到前一个节点,因为有可能会删除尾节点
        }
        prev = cur; // 保存前一个节点的地址
        cur = cur->next;
    }

    return head;
}


int main()
{
    Node* head = NULL;
    
    // 尾插节点
    printf("尾插节点: ");
    head = InsertAtTail(head, 1);
    head = InsertAtTail(head, 2);
    head = InsertAtTail(head, 6);
    head = InsertAtTail(head, 3);
    head = InsertAtTail(head, 4);
    head = InsertAtTail(head, 5);
    head = InsertAtTail(head, 6);
    Print(head);

    
    printf("移除: ");
    head = Remove(head, 6);
    Print(head);


    return 0;
}




/*
提交的代码
struct ListNode* removeElements(struct ListNode* head, int val) {
      // [1][2][3]
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;

    // 当前节点是否删除
    while(cur != NULL && cur->val == val)
    {   
        cur = head->next; // 下一个节点
        free(head); 
        head = cur; // 成为新头
    }

    // 这个if不能去掉
    if(NULL == head)
    {
        return head;
    }

    // 处理中间和尾节点
    while(cur)
    {
        
        // 判断是否删除节点
        if(cur->val == val)
        {
            // 前一个节点链接后一个节点
            prev->next = cur->next;
            // 删除节点
            free(cur);
            cur = prev; // 回到前一个节点,因为有可能会删除尾节点
        }
        prev = cur; // 保存前一个节点的地址
        cur = cur->next;
    }

    return head;
}

*/