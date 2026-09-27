#include "Stack.h"

// 入栈/压栈
Node* Push(Node* top, int val)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

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
Node* Pop(Node* top)
{
    // [1][2][3]
    if(NULL == top)
    {
        printf("栈中没有元素可以弹出!\n");
        return top; 
    }
    Node* next = top->next;
    free(top); // 释放栈顶元素
    return next;
}

// 返回栈顶元素
Node* Top(Node* top)
{
    if(NULL == top)
    {
        printf("栈中没有元素可以返回!\n");
        return NULL;
    }
    return top;
}

// 栈是否为空
// - 栈为空返回true,否则返回false
bool IsEmpty(Node* top)
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


void Print(Node* top)
{
    // [2][3][1]
    while(top)
    {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}