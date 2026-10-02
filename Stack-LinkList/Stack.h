#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 基于单链表实现的栈

typedef int StackType;

// 声明节点
typedef struct Node
{
    StackType data;
    struct Node* next;
}Stack;



// 入栈/压栈
Stack* Push(Stack* top, StackType val);

// 出栈/弹出栈顶元素
Stack* Pop(Stack* top);

// 带回栈顶元素
void Top(Stack* top, StackType* out);

// 栈是否为空
bool IsEmpty(Stack* top);

void Print(Stack* top);