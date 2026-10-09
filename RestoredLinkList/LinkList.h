#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 重命名数据类型
typedef int ElementsType;

// 声明节点
typedef struct Node
{
    ElementsType Data;
    struct Node* Next;
}Node;

// 头插节点
void InsertFront(Node** Phead, ElementsType val);

// 输出链表
void Print(Node* head);

// 尾插节点
void InsertTail(Node** Phead, ElementsType val);

// 头删节点
void DelFront(Node** Phead);

// 尾删节点
void DelTail(Node** Phead); 

// 任意位置插入节点
void InsertPosNode(Node** Phead, ElementsType val , int pos);

// 删除任意位置节点
void DelPosNode(Node** Phead, int pos);

// 释放链表
void DestroyList(Node** Phead);