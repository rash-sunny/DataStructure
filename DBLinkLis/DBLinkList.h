// 函数声明以及头文件

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LinkListType; // 重命名数据类型

// 声明双链表节点
typedef struct Node
{
    LinkListType data; // 数据
    struct Node* next; // 链接下一个节点
    struct Node* prev; // 链接上一个节点
}Node;



// 头插
Node* InsertAtHead(Node* head, LinkListType val);

// 输出
void Print(Node* head);

// 反向输出
void ReversePrint(Node* head);

// 尾插
Node* InsertAtTail(Node* head, LinkListType val);


// 头删
Node* PopHeadNode(Node* head);

// 尾删
Node* PopTailNode(Node* head);


// 删除任意位置节点
Node* DelPosNode(Node* head, int pos);

// 任意位置插入节点
Node* InsertPosNode(Node* head, int pos, LinkListType val);

// 反转链表
Node* Reverse(Node* head);