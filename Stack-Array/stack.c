#include <stdio.h>
#include <stdbool.h>


#define SIZE 4

int arr[SIZE];
int top = -1; // 空栈

// 压栈
void Push(int val)
{
    // 判断是否溢出
    if(top == SIZE-1) // 因为数组的最大下标是SIZE-1,如果SIZE=4 [0][1][2][3] 最大下标是3
    {
        printf("栈已满,无法压入元素!\n");
        return;
    }
    arr[++top] = val; // 压入元素
}

// 弹出栈顶元素
void Pop()
{
    if(-1 == top)
    {
        printf("没有可弹出元素!\n");
        return;
    }
    top--; 
}

// 返回栈顶元素
int Top()
{
    return arr[top];
}

// 栈是否为空
bool IsEmpty()
{
    if(-1 == top)
        return true;
    else
        return false;
}


void Print()
{
    for(int i= 0; i<=top; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

}


int main()
{
    printf("压入元素: ");
    Push(4);
    Push(6);
    Push(8);
    Print(); // 4 6 8


    printf("弹出栈顶元素: ");
    Pop();
    Print(); // 4 6

    printf("返回栈顶元素: ");
    int ret = Top();
    printf("%d \n", ret); // 6

    printf("判断栈是否为空: ");
    int flag = IsEmpty();
    printf("%s\n", flag?"true":"false"); // false

    return 0;
}


// 注：Print函数并不是一个栈的典型操作，这里只是为了测试