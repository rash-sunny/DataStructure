#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 基于单链表实现栈

typedef int StackType;

#define SIZE 10

// 声明节点
typedef struct Node
{
	StackType data;
	struct Node* next;
}Stack;


// 压栈
void Push(Stack** top, StackType val);

// 弹出栈顶元素
void Pop(Stack** top);

// 检查栈是否为空
int IsEmpty(Stack* top);

// 返回栈顶元素
void Top(Stack* top, StackType* out);
