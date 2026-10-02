#include "Stack.h"

// 测试栈的实现
static void test01()
{
    Stack* top = NULL;
    
    top = Push(NULL, 2);
    top = Push(top, 4);
    top = Push(top, 6);
    printf("入栈: ");
    Print(top);

    top = Pop(top);
    printf("弹出栈顶元素: ");
    Print(top);

    StackType out = 0;
    Top(top, &out); // 返回栈顶元素
    printf("当前栈顶个元素: %d\n", out);
    bool flag = IsEmpty(NULL);
    printf("栈是否为空: %s\n", flag?"true":"false");
}


// 反转字符串
static void test02()
{
    char str[51] = {0};
    printf("输入一个字符串: ");
    scanf("%s", str);

    printf("反转前: %s\n", str);


    // 创建一个栈
    Stack* s = NULL;
    

    // 压栈
    for(int i = 0; i<strlen(str); i++)
    {
        // 把所有字符压入栈中
        s = Push(s, str[i]);
    }


    StackType val = 0;
    // 把栈中字符从栈顶开始重新写入数组
    for(int i = 0; i<strlen(str); i++)
    {
        // Top(s, str+i);
        Top(s, &val);
        str[i] = (char)val;
        s = Pop(s); // 弹出栈顶元素
    }
    printf("反转后: %s\n", str);
}


// 反转链表
static void test03()
{

    // 创建一个栈
    Stack* s = NULL;

    // 创建链表
    Stack* head = NULL;
    // 头插节点
	head = Push(head, 1);
    // head = Push(head, 2);
    head = Push(head, 3);
    head = Push(head, 2);
    // head = Push(head, 1);
    printf("反转前的链表: ");
    Print(head); // 3 2 1 因为是头插法，所以是逆序的
   
   
    Stack* temp = head;
    // 压栈
    for(; temp != NULL; temp = temp->next)
    {
        s = Push(s, temp->data); // 这里压入的是data值也就是int类型的数据
    }

    temp = head;
    // 反转链表
    for(; temp != NULL; temp=temp->next)
    {
        Top(s, &(temp->data));
        s = Pop(s); // 弹出栈顶元素
    }

    printf("反转后的链表: ");
    Print(head); // 1 2 3


    /*
        这里的反转和之前写单链表的反转思路不一样。之前是修复每个节点的next字段让它指向前一个节点，这是经典的写法
        
        这里是修改每个节点data字段的值。因为Push函数第2个参数 val 是int类型，所以压栈压的是 节点data字段的值,
        而不是节点。
    */

}


int main()
{
    // test01(); // 测试栈
    test02(); // 反转字符串

    test03(); // 反转链表 - 修改data字段
    
    return 0;
}

// 注：Print函数不属于一个栈的操作，这里是为了测试栈的实现是否正确



/*
    修改：
    - 修改了重命名结构体类型为Stack，原来是Node。刚学完链表习惯了，哈哈改成Stack语义更好些
    
    - 修改了Top返回值为 void 之前的返回值为 Node*
    为什么要修改为void呢？之前我分析如果返回的是int，那么栈为空时不知道该返回什么；但是这会导致一个问题
    返回Node* 别人调用Top的时候就可以通过返回来的指针修改该节点的指向。这就破坏了栈了

    所以，设为void，然后再加一个参数，StackType* out ，直接把栈顶元素写入out里带出来


*/