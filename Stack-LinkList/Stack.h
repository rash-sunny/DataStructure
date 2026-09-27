#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 基于单链表实现的栈


// 声明节点
typedef struct Node
{
    int data;
    struct Node* next;
}Node;



// 入栈/压栈
Node* Push(Node* top, int val);

// 出栈/弹出栈顶元素
Node* Pop(Node* top);

// 返回栈顶元素
Node* Top(Node* top);

// 栈是否为空
bool IsEmpty(Node* top);

void Print(Node* top);