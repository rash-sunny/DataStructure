#include "stack.h"


// 压栈
void Push(Stack** top, StackType val)
{
	Stack* temp = (Stack*)malloc(sizeof(Stack));

	if (NULL == temp)
	{
		perror("malloc");
		return;
	}
	
	// 头插
	temp->data = val;
	temp->next = *top;
	
	*top = temp;
}

// 弹出栈顶元素
void Pop(Stack** top)
{
	if (IsEmpty(*top))
	{
		printf("栈为空，没有元素可以弹出\n");
		return;
	}

	Stack* next = (*top)->next;
	free(*top); // 释放栈顶元素
	*top = next;
}

// 检查栈是否为空
// 栈为空返回真，否则返回假
int IsEmpty(Stack* top)
{
	if (NULL == top)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


// 带回栈顶元素
void Top(Stack* top, StackType* out)
{
	// 是否为空
	if (IsEmpty(top))
	{
        return;
	}
	
	*out = top->data; // 带回栈顶元素
}