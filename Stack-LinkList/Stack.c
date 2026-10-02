#include "Stack.h"

// 入栈/压栈
Stack* Push(Stack* top, StackType val)
{
    Stack* newNode = (Stack*)malloc(sizeof(Stack));

    if(NULL == newNode)
    {
        perror("malloc");
        return NULL;
    }

    // 头插法
    newNode->data = val;
    newNode->next = top;
    return newNode;
}

// 出栈/弹出栈顶元素
Stack* Pop(Stack* top)
{
    // [1][2][3]
    if(NULL == top)
    {
        printf("栈中没有元素可以弹出!\n");
        return top; 
    }
    Stack* next = top->next;
    free(top); // 释放栈顶元素
    return next;
}

// 带回栈顶元素
void Top(Stack* top, StackType* out)
{
    if(NULL == top)
    {
        printf("栈中没有元素可以返回!\n");
        return;
    }

    *out = top->data; // 带回栈顶元素
}

// 栈是否为空
// - 栈为空返回true,否则返回false
bool IsEmpty(Stack* top)
{
    if(top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void Print(Stack* top)
{
    // [2][3][1]
    while(top)
    {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}