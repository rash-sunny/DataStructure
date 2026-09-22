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



// Node* Remove(Node* head, int val)
// {
//     Node* cur = head;
//     Node* prev = NULL;

//     // 删头节点
//     while(cur != NULL && cur->data == val)
//     {   
//         cur = head->next; // 下一个节点
//         free(head); 
//         head = cur; // 成为新头
//     }

//     // 删中间和尾节点
//     while(cur)
//     {
//         // 判断是否删除节点
//         if(cur->data == val)
//         {
//             // 前一个节点链接后一个节点
//             prev->next = cur->next;
//             // 删除节点
//             free(cur);
//             cur = prev; // 回到前一个节点,因为有可能会删除尾节点
//         }
//         prev = cur; // 保存前一个节点的地址
//         cur = cur->next;
//     }

//     return head;
// }


// 解法一
// Node* Remove(Node* head, int val)
// {
//     Node* cur = head;
//     Node* temp = NULL;
//     // 删头节点
//     while(cur != NULL && cur->data == val)
//     {   
//         cur = head->next; // 下一个节点
//         free(head);
//         head = cur; // 成为新头
//     }

//     // 删中间和尾节点
//     while(cur && (temp = cur->next))
//     {
//        if(temp->data == val)
//        {
//             cur->next = temp->next;
//             free(temp);
//        }
//        else
//        {
//             cur = cur -> next;
//        }
//     }

//     return head;
// }


// 解法二
Node* Remove(Node* head, int val)
{
    // 创建虚拟头节点
    Node* dummyHead = (Node*)malloc(sizeof(Node));
    dummyHead->next = head;
    Node* cur = dummyHead;

    // 遍厉链表
    while(cur->next != NULL)
    {
        // 是否删除该节点
        if(val == cur->next->data)
        {
            Node* temp = cur->next; // 要删除的节点地址
            cur->next = cur->next->next; // 下一个节点
            // 删除节点
            free(temp);
        }
        else
        {
            cur = cur->next;
        }
    }

    // 跟新head指向
    head = dummyHead->next;
    // 释放虚拟节点
    free(dummyHead);
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
    // head = Remove(head, 6);
    head = Remove(NULL, 6);
    Print(head);
    return 0;
}




/*
提交的代码（方法1）
 struct ListNode* cur = head;
    struct ListNode* prev = NULL;

    // 删头节点
    while(cur != NULL && cur->val == val)
    {   
        cur = head->next; // 下一个节点
        free(head); 
        head = cur; // 成为新头
    }

    // 删中间和尾节点
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


*/




/*
// 提交的代码（方法2）
// 创建虚拟节点
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->next = head;  // 虚拟头节点
    struct ListNode* cur = dummyHead; // 临时变量遍历链表

    while(cur->next != NULL)
    {
        // 是否要删除节点
        if(val == cur->next->val)
        {

            struct ListNode* delNode = cur->next; // 保存要删除的节点
            cur->next = cur->next->next; // 更新cur->next的指向
            // 删除节点
            free(delNode);
        }
        else
        {
            cur = cur->next;
        }
    }

    // 重置head的指向
    head = dummyHead->next;
    free(dummyHead); // 释放虚拟的头节点
    return head;

*/