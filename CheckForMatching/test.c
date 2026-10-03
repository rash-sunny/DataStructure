#include "stack.h"

static void Print(Stack* top)
{
	if (IsEmpty(top))
	{
		printf("栈中没有任何元素\n");
		return;
	}

	printf("栈中元素: ");
	// [1][2][3]
	for (; top != NULL; top = top->next)
	{
		printf("%d ", top->data);
	}
	printf("\n");
}


static void test01()
{
	// 创建一个栈
	Stack* stack = NULL;
	// 压栈
	Push(&stack, 2);
	Push(&stack, 3);
	Push(&stack, 5);
	//Push(&stack, 7);

	Print(stack);

	// 返回栈顶元素
	StackType out = 0;
	Top(stack, &out);
	printf("%d\n", out);

	// 弹出栈顶元素
	Pop(&stack);
	Pop(&stack);
	//Pop(&stack);
	//Pop(NULL);

	Print(stack);
}



// 检查括号的类型
int Elements(char src, void (*Top)(Stack*, StackType*), Stack* s)
{
    int out = 0;
    Top(s, &out); // 带回栈顶元素
    
    // 栈顶括号和src的括号不相等，说明括号类型不同
    if(src == ')' && out != '(')
        return 1;
    if(src == ']' && out != '[')
        return 1;
    if(src == '}' && out != '{')
        return 1;

    // 匹配
    return 0;

    /*
        判断当前栈顶和当前src字符是否为一对括号。把左括号压入栈中，右括号是src
        若当前栈顶的左括号和src的右括号是一个类型，那么则匹配
        否则不匹配

        也就是栈顶元素和当前src的括号类型是否匹配
    
        这里的返回值是：不匹配返回真，匹配返回假。这样在调用的时候就不用进行逻辑取反操作了；我个人觉得阅读起来也会好点

    */
}



static void test02()
{
    // 创建一个栈
    Stack* s = NULL;
    char str[SIZE] = {0};

    printf("请输入: ");
    scanf("%s", str);

    // 压栈
    for(int i = 0; i<strlen(str); i++)
    {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            Push(&s, str[i]); // 压入左括号
        }
        else if(str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if(IsEmpty(s) || Elements(str[i], Top, s))
            {
                printf("不匹配\n");
                return;
            }
            else
            {
                Pop(&s); // 弹出栈顶元素
            }
        }
    }
    
    // 最后栈为空则是匹配
    if(IsEmpty(s))
    {
        printf("匹配\n");
    }
    else
    {
        printf("不匹配\n");
    }
}


int main()
{
	// test01();

    test02(); // 检查括号是否匹配

	return 0;
}