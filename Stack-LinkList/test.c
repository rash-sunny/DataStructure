#include "Stack.h"

// 测试栈的实现
static void test01()
{
    Node* top = NULL;
    
    top = Push(NULL, 2);
    top = Push(top, 4);
    top = Push(top, 6);
    printf("入栈: ");
    Print(top);

    top = Pop(top);
    printf("弹出栈顶元素: ");
    Print(top);

    Node* n = Top(top);
    if(n) // 防止访问空指针
    {
        printf("返回栈顶元素: %d\n", n->data);
    }
    bool flag = IsEmpty(NULL);
    printf("栈是否为空: %s\n", flag?"true":"false");
}


void Reverse(char* src, size_t len)
{
    // 创建站
    Node* stack = NULL;
    int top = 0; // 标记栈顶

    // 压栈
    for(int i = 0; i<len; i++)
    {
        stack = Push(stack, src[i]);
    }

    // 出栈
    for(int i= 0; i<len; i++)
    {
        src[i] = Top(stack)->data; // 返回栈顶元素重新写入数组
        // 弹出栈顶元素
        stack = Pop(stack); 
   }
}


static void test02()
{
    char str[51] = {0};
    printf("输入一个字符串: ");
    scanf("%s", str);

    printf("反转前: %s\n", str);
    Reverse(str, strlen(str)); // 反转字符串
    printf("反转后: %s\n", str);
}


int main()
{
    // test01(); // 测试栈
    test02(); // 反转字符串
    
    return 0;
}

// 注：Print函数不属于一个栈的操作，这里是为了测试栈的实现是否正确