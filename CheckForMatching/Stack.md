[toc]

##### 栈

栈，作为一种抽象数据类型或者说ADT。把它作为一种抽象数据类型讨论时，只是讨论它的特性和操作，不讨论它的具体实现。

#### 栈的简介

栈其实和生活中的一些物品还是很像的，比如下面的这组羽毛球。如果想要把这个罐子中的羽毛球拿出来，只能从上面打开先拿出最上面的一个，以此类推...  栈其实和这个是很像的

==栈的属性：栈中的元素必须从一端（一端，称为栈顶）插入或删除，这是属性同时也是一种规则（限制）只能访问栈顶，任何元素都必须从栈顶插入或删除。==

<img src="C:\Users\sunny\AppData\Roaming\Typora\typora-user-images\image-20260925204849960.png" alt="image-20260925204849960" style="zoom: 50%;" />

**栈的定义：**==栈是一个列表或集合，要想插入或删除元素只能从一端进行（一端，称为栈顶）==

栈有两种基本操作：

1. 插入操作（也称为`push`操作，压栈/推入栈的意思）
2. 弹出操作（也称为`pop`操作，弹出/移出元素的意思）
    1. `pop`弹出的是**最近插入到栈中的元素**

`push&pop`是最基本的操作，当然还有其它的操作如**返回栈顶元素，这种操作称为`top`；以及`IsEmpty`操作可以判断一个栈是否为空，如果栈为空返回`true`否则返回`false`**

对于`push&pop`来说，每次只能往栈顶推入一个元素或者说插入一个元素，以及从栈顶移出一个元素。上述的所有操作它们的时间复杂度都是O(1)，常数时间内完成

可以把栈看做下图中的图形，现在里面什么都没有（空栈）不能`pop`（弹出任何元素）。

![image-20260926003414023](C:\Users\sunny\AppData\Roaming\Typora\typora-user-images\image-20260926003414023.png)

现在来压入一些整形元素：
![image-20260926004244665](C:\Users\sunny\AppData\Roaming\Typora\typora-user-images\image-20260926004244665.png)

往栈压入了一个整形元素4，现在只有它一个元素那么它就是位于栈顶。如果再往栈压入元素，那么4就不再位于栈顶了，最近压进来的元素位于栈顶。如下图：
![image-20260926004555145](C:\Users\sunny\AppData\Roaming\Typora\typora-user-images\image-20260926004555145.png)

应该不难看懂，`Top`前面也提到过可以返回栈顶上的元素。现在，如果要执行`pop`操作，那么将会把6从栈顶弹出。如图：
![image-20260926004911856](C:\Users\sunny\AppData\Roaming\Typora\typora-user-images\image-20260926004911856.png)

现在栈里面只有一个元素4，如果执行`IsEmpty`操作会返回一个`false`因为栈不为空。如果再次执行`pop`将会把4弹出，那么栈就为空了

看到这里相信你也有点明白了，不就是先进来的元素最后出去吗？是的！==所以，最后插入栈中的元素，将会是第一个被弹出。先进后出，后进先出==（我个人把它理解为栈的规则）



#### 栈的应用场景

- 可以用来帮助执行函数也可以用来实现递归，因为递归就是函数调用链（自己调用自己）。
- 也可以用来实现编辑器的撤回操作，就是平时码字的时候对应的快捷键（`ctrl+z`）
- 还可以用来验证比如源码中的括号是否匹配



#### 栈的实现

看了前面的简介，我们知道**栈是一种列表或集合**。==栈的限制：在执行`Push&Pop`操作的时候，每次只能操作一个元素。且只能从一端进行操作（一端，称为：栈顶）==

现在要实现栈，只需要给列表中增加额外的限制或者说约束：**插入或删除操作，比如从列表的一端进行**这样就可以得到一个栈。相信伙伴们也想到了用**数组**，这确实可以。

**实现栈的两种方式**

1. 数组
2. 链表



#### 数组的方式实现栈

现在要实现一个存放整形数据的栈，首先需要创建一个整形数组。
现在创建一个整形数组，大小为10
![image-20260926012846964](C:\Users\sunny\AppData\Roaming\Typora\typora-user-images\image-20260926012846964.png)

==这个数组就叫`arr`好了，要用它来做为栈。这个数组的一部分从0下标到`top`的这些元素就是栈==
**这个`top`变量是用来存放栈顶下标的**。那么如果这个栈为空，`top`就给它赋值为-1，当然也可以给其它值，但是不能给正整数；因为这将会和数组的下标“冲突”。来随便写点代码：

```c
int arr[10];
int top = -1; // 表示空栈

// 压栈
Push(int val)
{
    ++top;
    arr[top] = val;
}
```

这是伪代码，假设要`Push(4)、Push(6)、Push(8)`每次`Push`操作都会往下标大的位置增长
![image-20260926013927593](C:\Users\sunny\AppData\Roaming\Typora\typora-user-images\image-20260926013927593.png)

再来看看怎么弹出元素：
```c
int arr[10];
int top = -1; // 表示空栈

// 压栈
Push(int val)
{
    ++top;
    arr[top] = val;
}

Pop()
{
    --top;
}
```



![image-20260926014225028](C:\Users\sunny\AppData\Roaming\Typora\typora-user-images\image-20260926014225028.png)

如果调用`Pop`函数，`top`就会减1；但是在没减1之前的下标元素可以不用做任何处理，因为这是数组。它在内存是连续存放的，下一次`Push`的时候如果达到该位置会把这个值给覆盖掉

现在实现的两个函数`Push&Pop`它们的时间复杂度都是O(1)。==但是，我们之所以能够往这个栈压入元素是因为数组的空间还没有使用完，如果数组的空间用完了，就无法压入了，会导致溢出== 该怎么办？之前学习过顺序表，顺序表的底层也是数组呀，还记得吧。如果用完了再给数组扩容就好了，以2倍扩对吧。也就是动态数组吗，如果说这个栈被使用完了，那么我就给数组扩容，然后再把原来栈里的元素拷贝到新的数组。拷贝的时间复杂度是O(n)然后花费常数时间来执行`Push`操作。
在这种情况下，`Push`操作的时间复杂：

- 最好的情况：O(1)
- 最坏的情况：O(n)
- 平均情况下：O(1)

除了`Push&Pop`操作，前面还提到过`Top`返回栈顶的元素，以及`IsEmpty`
```c
Top()
{
    return arr[top]; // 返回栈顶元素
}
```

检查栈是否为空：
```c
IsEmpty()
{
    if( -1 == top)
		return true; // 为空返回true
	else
        return false; // 非空返回false
}
```

以下是数组的方式来实现栈，代码比较简单，我就不多说了
```c
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
    if(top == -1)
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
    if(top == -1)
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
```

这里并没有使用动态数组来实现，无论是动态数组或是数组的方式我都不打算用，所以这里就写简单点了。



#### 单链表方式实现栈

用来链表来实现和数组的方式相比我觉的链表比较优雅。

对于链表来说，不需要担心溢出的问题除非用完了电脑的内存。为了在节点中存放下一个节点的地址会使用一些额外的内存空间，但我们只需要的时候使用内存，不需要的时候就释放内存。从某种程度上来说`Push&Pop`用链表的方式来实现更加优雅。

==但是，这并不代表数组的方式来实现栈比链表差。实际上从性能的角度出发，动态数组的方式更加简单且更优==

那么用链表的方式又该怎么做呢？如果说现在有一个链表，然后要`Push(2)`如果使用尾插法的话最坏的情况下是O(n)，在`Pop`的时候也是O(n)。而前面又说栈的`Push&Pop`操作以及`Top&IsEmpty`操作都是O(1)。所以，这里还不能用尾插法来做。应该要用头插。

代码相对来说还是比较简单的，这里我还是分成多文件来写代码：

**stack.h**

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 基于单链表实现的栈

// 声明节点
typedef struct Node
{
    int data;
    struct Node* next;
}Node;


// 入栈/压栈
Node* Push(Node* top, int val);

// 出栈/弹出栈顶元素
Node* Pop(Node* top);

// 返回栈顶元素
Node* Top(Node* top);

// 栈是否为空
bool IsEmpty(Node* top);

void Print(Node* top);
```

**stack.c**

```c
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
    if(NULL == top)
    {
        printf("栈中没有元素可以弹出!\n");
        return NULL;
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
        return top;
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
    while(top)
    {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}
```

**test.c**

```c
#include "Stack.h"

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
    if(n)
    {
        printf("返回栈顶元素: %d\n", n->data);
    }
    bool flag = IsEmpty(NULL);
    printf("栈是否为空: %s\n", flag?"true":"false");
}


int main()
{
    test01();

    return 0;
}
```



`Push`函数和之前写单链表的时候并不太一样，之前写是这样的：

```c
Node* Create(Node* top, int val)
{
 	
   Node* newNode = (Node*)malloc(sizeof(Node));

    if(NULL == newNode)
    {
        perror("malloc");
        return NULL;
    }

    newNode->data = val;
    newNode->next = NULL; 
    return newNode;
}
    
Node* Push(Node* top, int val)
{
  	Node* temp = Create(top, val);
    temp->next = top;
    top = temp;
    return top;
}
```

为什么之前需要一个`Create`函数呢？因为之前还有一个头插以及任意位置插入，无论是什么插入都是需要创建节点，所以把这个逻辑给抽出来单独写，每次去调用该函数。而且每次创建的节点其`next`字段都为`NULL`，只有在需要的时候才会修改`next`链接。比如头插，无论是空链表还是非空链表一上来`Create`都会把`next`字段置为空，然后在实现头插的时候才会把`next`字段建立链接。假设现在是一个非空链表，那么头插需要把之前的头节点改成新插入的节点，也就是`top = temp;`但是在这之前还需要给待插入的节点和当前链表的头节点建立链接；所以还需要`temp->next = top;` 本质上是一样的。

现在要往栈中压入：`Push(top, 2)` 此时`top`为空，`val=2` 进入`Push`函数创建节点`newNode`创建成功执行：`newNode->data= val;`这没啥好说的就是给节点中的数据域放入2，然后`newNode->next = top;` 这就是把节点中指针域设为当前`top=NULL`也就是空。最后直接返回`newNode`新节点的地址。

这么看可能没看出来啥，再来`Push(top, 4)`此时`top`不再为空，栈中有一个数据4，进入`Push`然后创建节点`newNode`创建成功其数据域设为当前`val`值也就是4，然后设置其指针域`newNode->next = top;`前面压入了一个2，所以现在`top`之前压入节点的地址，所以这条语句就是把新节点的指针域指向`top`最后返回新节点。

---

再来看`Pop`函数，现在栈中已经有了2个元素分别是：2,4其中4是在栈顶的。然后先在要弹出栈顶的元素，也就是4，已进入`Pop`函数就先判断一下栈中是否为空，如果为空就返回`NULL` 现在栈是非空的，所以不会执行`if`语句。如果没有`Node* next = top->next;`，直接`free()`的话就得不到栈中的元素2了。所以先把栈中2的地址存起来，然后再释放栈顶的元素，最后返回栈中的元素即可。

剩下的两个函数相对来说还是比较简单的，就不多说了。==注：`Print`函数并不是一个栈的操作，这里只是为了测试我的实现是否正确。==

最后提一嘴`IsEmpty`函数，它的返回值是`bool`类型，当然也可以直接返回`int`类型。我这里是为了更直观的看到`true&false`才使用的。可能你会问C语言不是没有`bool`类型吗？其实是有的，在C99标准起引入了`bool`类型，但是使用的时候需要包含头文件`stdbool.h`

---

对于`test.c`需要注意的点也就只有一个，就是`Top`函数的返回值是`Node*`为什么要设计成这样？因为我用的是`mingW64`下的`gcc`编译器，如果把返回值设置成`int`的话虽说也可以，但是在`top`为空的情况下我不知道该返回啥了。如果直接写`return;`是不行的！在IDE  VS环境下允许这么做。所以，我这了就设置返回类型为`Node*`用n接收其返回值，还要做个判断，这是因为如果返回的是`NULL`那么直接`n->data`就会造成对空指针的访问。

---



#### 栈的使用

现在我们已经知道了用数组来实现栈以及单链表来实现栈，但是栈该怎么使用呢或者说什么时候使用栈呢？来看看简单使用栈的场景吧:elephant:

==栈，可以用来反转一个链表或是集合，或简单地反向遍历一个链表或集合。因为，它的特性是：后进先出。==接下来讲讨论用栈来反转字符串以及反转链表

##### 反转字符串

先来看看字符串的反转，有一个字符串`char str = "hello";`字符串的结束标志是`\0`。"hello"反转后是"olleh"，先用栈来反转链表看看效率怎么样。

![image-20260927231930098](C:\Users\sunny\AppData\Roaming\Typora\typora-user-images\image-20260927231930098.png)

先来创建一个存放字符串的栈，恰好我们前面基于单链表实现了一个栈🥰。创建好栈之后把数组中的所有字符串全部压入栈中就像下面这样：

![image-20260927231943814](https://picgocloud.com/m/1b3acbdb-9126-425c-b3c5-d7dfce8a964a.png)

当我们把字符串中的所有字符全部都压入栈后，此时的栈像图中一样。来看看代码：

```c
void Reverse(char* src, size_t len)
{
    // 创建栈
    Node* stack = NULL;

    // 压栈
    for(int i = 0; i<len; i++)
    {
        stack = Push(stack, src[i]);
    }
}
```

那么该怎么让它反转过来呢？还记得`Top`操作把，**返回栈顶元素**，所以我们通过`Top`来返回栈顶的元素，然后再放入数组中即可，这样就会把元素数组中的字符给覆盖掉，因为数组是连续存放的。比如现在把栈顶元素也就是`'o'`弹出来然后要存放到数组下标0的位置，然后`Pop`操作弹出栈顶元素，现在栈顶就的元素是`l`，然后存放数组下标1的位置，以此类推....

你可能会问：

- 这个栈是基于单链表实现的 ，而节点成员是`int`；但是字符是`char`类型的，这不会冲突吗？
    答：不会的，因为字符的本质是`ASCII`码值，本质上还是`int`，这里会隐式转换`int`的。不用担心

- 在实现栈的时候`Top`函数的返回值是`Node*`，可是要返回的类型是`char`这不对吧？

    答：如果直接返回`char`确实不对！但是，我们可以返回之后可以直接操作数据域也就是`data`，为什么？因为本质上返回的还是节点呀👍

废话不多说，我们来吧`Reverse`函数的出栈逻辑写一下吧
```c
void Reverse(char* src, size_t len)
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

```

> 时间复杂度分析：
> 前面我们说，栈上的操作都是常数时间也就是O(1)无论是`Push、Pop、Top、IsEmpty`都是常数时间。因此`Reverse`函数中的两个循环体代码都花费常数时间。
>
> ```c
> stack = Push(stack, src[i]);
> 
>  src[i] = Top(stack)->data; // 返回栈顶元素重新写入数组
> // 弹出栈顶元素
> stack = Pop(stack); 
> ```
>
> 第一个循环跑了len次，第2个循环也跑了len次。第一个循环的时间复杂度是O(n)，第二个循环的时间复杂度是O(n)。循环不嵌套的而是一个接着一个，在这种情况下整个函数的时间复杂度也是O(n)
>
> 每次都是把数组中所有的字符压入栈中，所以栈上使用的内存会和数组的长度也就是字符串的长度成正比，因此空间复杂度是O(n)

还有其它的方法来反转字符串，不需要使用额外的空间来反转呢？
我们用两个变量来记录左下标（0）以及右下标（`strlen(str)-1`），然后收尾交换：

```c
void Reverse()
{
    char str[10] = "hello";
    int start = 0;
    int end = strlen(str)-1;
    printf("反转前: %s\n",str);

    while(start < end)
    {
        // 交换
        int temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }

    printf("反转后: %s\n",str);
}
```

这个算法的空间复杂度是O(1)，时间复杂度还是O(n)。比使用栈的方法更好一些。



##### 反转链表

之前在反转链表的时候，使用了迭代的方法和递归的方法。迭代的方法时间复杂度是O(n)，空间复杂度是O(1)。使用递归的方法不是显示地创建一个栈，但是在计算机内存中会使用栈内存区的空间；递归方法的时间复杂度是O(n)，空间复杂度也是O(n)。

现在基于单链表实现了栈，来看看怎么使用这个栈来反转链表。可以把这个栈理解为显示的栈。



来看看怎么做。首先，我们遍历这个需要反转的链表，每遇到一个节点就压入栈中，就像图中那样。

![image-20260927203816808](C:\Users\sunny\AppData\Roaming\Typora\typora-user-images\image-20260927203816808.png)

临时变量`temp`来遍历链表，每次遇到一个节点就`data`字段存放的值压入栈中。然后开始反转，`head`一直保持不变，我们对`temp`操作。
当把链表中所有节点的`data`字段的存放的值都压入栈后，`temp`就为空了，所以在反转前还让`temp`指向头节点。现在栈顶的值为3，我们返回栈顶的值将其写入到当前的`temp`节点的`data`字段中。接着弹出头节点；然后``temp`来到下一个指针，以此类推....

==也就是说我们修改的是节点的`data`字段存放的值，而不是修改`next`字段的指向==

```c
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

```



- 问：为什么不直接压入节点，然后反转的时候修改`next`字段的指向，使它指向前一个节点且不是更直观吗？

    答：是的，但是很遗憾，`Push`第2个参数的类型是`int`所以无法压入栈中。所以这里采用的是压入`data`字段

这就是我学习栈的过程啦🥰如果有错误的地方欢迎大家评论区指出



