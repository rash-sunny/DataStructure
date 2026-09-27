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


void Reverse_1(char* src, size_t len)
{
    // 创建栈
    Node* stack = NULL;

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
    Reverse_1(str, strlen(str)); // 反转字符串
    printf("反转后: %s\n", str);
}




Node* Reverse_2(Node* head)
{
    Node* stack = NULL; // 创建一个栈
    Node* temp = head; // 临时变量遍历链表

    // 压栈
    for(; temp != NULL; temp = temp->next)
    {
        stack = Push(stack, temp->data);
    }
    // 栈中元素: [3][2][1]
    
    // printf("%d\n", Top(stack)->data); // 调试用的啦

    // 反转
    temp = head;
    while(!IsEmpty(stack))
    {
        temp->data = Top(stack)->data; // 返回栈顶元素
        stack = Pop(stack); // 弹出栈顶元素
        temp = temp->next;
    }
    return head;

    /*
        这里的反转和之前写单链表的反转思路不一样。之前是修复每个节点的next字段让它指向前一个节点，这是经典的写法
        
        这里是修改每个节点data字段的值。因为Push函数第2个参数 val 是int类型，所以压栈压的是 节点data字段的值,
        而不是节点。
    */

}


static void test03()
{
    // 创建链表
    Node* head = NULL;
    // 头插节点
	head = Push(head, 1);
    head = Push(head, 2);
    head = Push(head, 3);
    head = Push(head, 2);
    head = Push(head, 1);
    printf("反转前的链表: ");
    Print(head); // 3 2 1 因为是头插法，所以是逆序的
    // 反转
    head = Reverse_2(head);
    printf("反转后的链表: ");
    Print(head); // 1 2 3
}


int main()
{
    // test01(); // 测试栈
    // test02(); // 反转字符串

    test03(); // 反转链表 - 修改data字段
    
    return 0;
}

// 注：Print函数不属于一个栈的操作，这里是为了测试栈的实现是否正确