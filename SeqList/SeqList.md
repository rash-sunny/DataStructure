[toc]







#### 顺序表

顺序表是线性表的一种

>  线性表是具有相同特性的数据结构的集合。
>
>  比如：
>
>  动物：狗、牛、羊、马.....
>
>  植物：花、草...
>
>  相同的特性来自两方面：
>
>  - 物理结构：不一定连续
>  - 逻辑结构：连续的
>
>  物理结构表示在内存中怎么存放的
>
>  逻辑结构表示想怎么去组织数据
>
>  那么顺序表无论是逻辑结构还是物理结构都是连续的，因为它的底层是数组；而数组在内存中是连续存放的



#### 顺序表分类

顺序表的底层结构是数组，在数组的基础上封装，从而实现常用的增、删、改、查。

- 静态顺序表
    - 顾名思义，使用定长的数组存储元素

- 动态顺序表
    - 确定大小后之后再去申请空间

#### 二、静态顺序表和动态顺序表的区别：

##### 2.1 静态顺序表

顺序表的底层是数组，用结构体封装起来。

```c
stuct SqeList
{
 	int arr[10]; // 定长数组
    int size; // 顺序表当前有效的数据个数
};
```

为啥`SqeList`还要有一个`size`成员？想象一下，这个数组的大小是10我不一定一次性就用完。我可能先存一个数据，所以再用一个成员来记录一下当前顺序表有效的数据个数



##### 2.2 动态顺序表

```c
stuct SqeList
{
 	int& arr; // 定长数组
    int size; // 顺序表当前有效的数据个数
    int capacity; // 空间大小
};
```

相比静态顺序表，动态顺序表多了一个`capacity`成员。假设已经给`arr`申请100个空间，然后已经用完了，然后我还想接着存数据，空间不够了需要去扩容。所以它的空间是会变化的，所以需要记住当前已经申请了多大的空间，后续再申请空间的时候，从这个空间的基础上去申请，因为肯定是不够了才去申请，如果刚开始都不知道申请了多大的空间，那么下次扩容的时候也不知道阔容多少呀。

##### 2.3 动态顺序表和静态顺序表的选择

静态顺序表：
对于静态顺序表来说，它是定长的数组。但是，这个数组的大小是多少呢？如果10后面可能不够用，如果给10000，可能又用不玩那就会造成浪费。给少了不够用，给多了用不完。

动态顺序表：
在开始的时候动态顺序表的大小是不确定的，我也不知道需要需要多大的空间。我要往里面插入数据那就需要去申请4个字节的空间，比如申请了100个空间，当这100个空间不够用上的时候，在这个空间的基础上去扩容。就算浪费但是对于静态顺序表来说，动态顺序表也不会浪费太多。

到这里就知道了，动态顺序表灵活一些



#### 3、动态顺序表的实现

所需要的文件：`SeqList.h(顺序表结构体、方法的声明)`,`SeqList.c(顺序表方法的实现)`,`test.c(测试顺序表)`

```c
// 对存储的数据类型重命名
typedef int SeqListDataType;

// 动态顺序表
typedef struct SeqList
{
	int* arr;
	int size; // 当前顺序表有效数据的个数
	int capacity; // 当前顺序表空间大小
}SL;
```

`arr`成员是一个`int*`指针，但是顺序表不一定要存整形数据呀，以后想要存放`float、char`这样的类型呢？总不能说顺序表封装数组后它只能存放整形的数据吧。所以，这里用`typedef`对``int`重命名一下`SeqListDataType`用来表示当前顺序表存放的数据类型，这么做的目的是什么？就算将来想要存`char`类型的数据，也只需要改`char* arr`就可以了呀，这不是多此一举吗？

其实不是的，想象一下，如果将来程序中的有1000个`int`类型的变量，现在要将部分`int`修改成`char`这就可能会造成漏改、改错等问题。重命名之后，将来我存储数据的时候，需要和结构体定义的类型保持一致，以后想要存放`char`我也只需要改成`typedef char SLDataType`即可

现在顺序表的结构已经定义好了，但是现在顺序表里的数组、有效数据个数、空间大小都还没有初始化。所以现在先来初始化顺序表



##### 3.1 初始化顺序表

```c
// 顺序表初始化
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0; 
}
```

注意：对结构体初始化也就是要给结构体成员赋值。那么在传参的时候肯定要把结构体地址传递过去，然后用结构体指针接收。

![image-20260828212547753](C:\Users\sunny\AppData\Roaming\Typora\typora-user-images\image-20260828212547753.png)

##### 3.2尾插

顺序表有三种插入的方式：头插、尾插、

```c
// 尾插
void SLPushBack(SL* ps, SeqListDataType n);
```

有两个参数：`SL* ps, SeqListDataType n` 注意：这里的`SeqListDataType`是`int`类型，只是我重命名了。

参数一：`SL* psps`表示往顺序表里去插入数据

参数二、`SeqListDataType n`表示我要插入的数据`n`

该怎么插入呢？假设现在有一个顺序表，`ps`指向这个顺序表，这个顺序表里面存放了些数据，如图下所示：

![image-20260828215335691](C:\Users\sunny\AppData\Roaming\Typora\typora-user-images\image-20260828215335691.png)

因为顺序表的底层是数组，所以这里画的图和画数组的图是一样的。

还有两个变量：`size`和`capacity`  `size`表示的是当前顺序表中有效的元素个数，`capacity`表示当前顺序表的空间大小。

以当前的顺序表为例：一共有4个空间，但是我只用了3个。所以`size=3`，`capacity=4`
现在我要插入一个6， 那么从哪里插？`size`和当前的顺序表的下标3对应起来了，所以是往`size`这个位置插入，多了一个数据，那么`size++`

```c
// 尾插
void SLPushBack(SL* ps, SeqListDataType n)
{
	// 插入数据
	ps->arr[ps->size++] = n;
}
```

但是，现在还是没法插入的，因为当前顺序表还没有空间。所以，在插入数据前要先申请空间所以要判断一下现在有没有空间。
```c
// 尾插
void SLPushBack(SL* ps, SeqListDataType n)
{   
    if(ps->capacity == 0) // 错误演示
    {
        
    }
    // 插入数据   
	ps->arr[ps->size++] = n;
}
```

但是这对吗？我们不妨思考一下，`capacity=0`的时候表示当前顺序表没有空间。假设现在的顺序表已经有了4个空间`capacity=4`但是我这4个空间已经放满了，此时的`size=4`那么还可以插入吗？肯定不能所以要去扩容空间。因此，要判断的是：当前空间够不够`if(ps->pacaity == ps->size)`如果当前的空间和当前的有效数据个数相同，说明当前的空间使用完了
```c
// 尾插
void SLPushBack(SL* ps, SeqListDataType n)
{   
    // 空间够不够
    if(ps->pacaity == ps->size) 
    {
        // 申请空间
    }
    // 插入数据   
	ps->arr[ps->size++] = n;
}
```

该怎么申请空间呢？在C语言中动态内存申请有三个函数：`malloc, calloc, realloc`应该用哪一个？来看看，比如第一次申请了4个空间然后这个空间用完了，那么需要在这个空间的基础上去扩容空间，所以这里应该用`realloc`。

但是申请多大的空间？或者说一次要扩容多大的空间？

==扩容空间一般都是以2或3倍去扩容。==这是数学推理出来的，用2或者3倍更加的合理。感兴趣的可以去查一下。

```c
// 尾插
void SLPushBack(SL* ps, SeqListDataType n)
{   
    // 空间够不够
    if(ps->pacaity == ps->size) 
    {
        // 申请空间
        ps->arr = (SeqListDataType*)realloc(ps->arr, capacity * 2 * sizeof(SeqListDataType));
    }
    // 插入数据   
	ps->arr[ps->size++] = n;
}
```

要记得乘以`sizeof(SeqListDataType)`，如果直接写：`realloc(ps->arr, capacity*2)`假设当前的`capacity=2` 那么2*2=4bytes 这是一个`int`的大小，那就变成了没次都申请一个`int`大小的空间了。

但是还有问题，在初始化的时候`capacity=0`这里申请的空间就没有任何意义了，因为0乘以任何数都得0。还有就是`realloc`申请空间失败的时候会返回一个`NULL`，这就会导致原来在顺序表中存放的数据丢失，所以申请空间也不能直接给`ps->arr`

先来判断`capacity`是不是为0，如果为0，那就给他一个`int`大小的空间，如果不为0就直接乘以2。你肯定也想到了，既然这么麻烦，为什么不在初始化的时候就给它一个默认大小的空间？事实上当然可以，只是我在学习的时候老师是这么讲的，所以，我觉得这样一步一步的去做可以知道，咦这个代码为什么要这写？哦~原来如此

那么既然`realloc`可能会申请失败，然后返回`NULL`，会造成之前已经存好的数据丢失；所以，这里申请空间可以先赋值给一个临时的指针变量：`SeqListDataType* tmp;` 然后判断`tmp`是否为`NULL`，如过不为空再把`tmp`申请的空间给`ps->arr`；`capacity`也跟着变化



```c
// 尾插
void SLPushBack(SL* ps, SeqListDataType n)
{
	assert(ps);

	// 空间是否足够
	if (ps->capacity == ps->size)
	{
		// 申请空间

		SeqListDataType newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SeqListDataType* tmp = (SeqListDataType*)realloc(ps->arr, newCapacity * sizeof(SeqListDataType));

		if (NULL == tmp)
		{
			// 申请失败
			perror("realloc");
			exit(1); // 退出程序
		}
		// 申请成功
		ps->arr = tmp; 
		ps->capacity = newCapacity; // 更新空间容量大小
	}
	// 插入数据
	ps->arr[ps->size++] = n;


}
```

现在尾插已经插入了之后，还得来释放一下空间呀，要知道`realloc`是向堆内存区申请空间的；如果释放内存那么在程序结束之后也会释放，但是假如说程序不结束呢？那就会造成堆内存区溢出（满了）或者内存泄漏。所以，现在应该要释放内存

```c
// 释放内存
void SLDestroy(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}
```



##### 3.3 头插

```c
void SLPushFront(SL* ps, SeqListDataType n);
```

头插也在顺序表的前面插入数据。先来看给当前的顺序表后插一些数据，相当于是添加数据了

![image-20260829190145504](C:\Users\sunny\AppData\Roaming\Typora\typora-user-images\image-20260829190145504.png)

现在顺序表中一共有5个有效数据，有8个空间？为什么是8个？因为刚开始的时候没有空间，默认是给了4个空间，然后以2倍去申请空间2*4=8个（注意这里说的不是bytes）`8*sizeof(SeqListDataType)`这里计算出来的才是bytes。

![image-20260829190717693](C:\Users\sunny\AppData\Roaming\Typora\typora-user-images\image-20260829190717693.png)



来看看头插，我现在想要往顺序表这个0下标的位置插入一个5；首先要从后面往前拿数据，然后往后移动。比如：2要移动到下标5的位置，9要移动到下标4，8移动到下标3....以此类推，最后0下标的位置就空出来了。

但是，并不是一上来就移动数据。比如顺序表中为空那肯定不需要做任何操作了，那么如果空间不够呢？还是有可能的，因为我这里初始化的是0，所以还要判断空间是否足够，于是就可以把前面尾插的申请空间代码封装函数，在插入数据前直接调用即可。

```c
// 扩容空间
void SLCheckCapacity(SL* ps)
{
	// 空间是否足够
	if (ps->capacity == ps->size)
	{
		// 申请空间

		SeqListDataType newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SeqListDataType* tmp = (SeqListDataType*)realloc(ps->arr, newCapacity * sizeof(SeqListDataType));

		if (NULL == tmp)
		{
			// 申请失败
			perror("realloc");
			exit(1); // 退出程序
		}
		// 申请成功
		ps->arr = tmp;
		ps->capacity = newCapacity; // 更新空间容量大小
	}
}
```

该怎么让数据后移呢？可以用循环啦，可以看上面画的图，我们知道`size`表示的是有效数据的个数，而`size`又刚好和顺序表的下标对应上了，既然要把2移动到下标5，也就是把前一个数据往后移动一个。那么循环变量`i`取值可以直接从`size`开始，每次都把`i-1`下标的数据往`i`移动；那么移动到哪里停止呢？分析一下，当把下标0的数据移动到下标1后就不需要移动了，所以循环条件应该是`i>0`

```c
// 头插
void SLPushFront(SL* ps, SeqListDataType n)
{
	assert(ps);
	
    // 申请空间
	SLCheckCapacity(ps);
	
	// 数据后移
	int i = 0;
	for (i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}

	ps->arr[i] = n; // 插入数据
	++(ps->size); // 有效数据+1

}
```

---



##### 3.4 在指定之前位置插入

```c
// 指定位置插入
void SLInsert(SL* ps, int pos, int n);
```

既然要指定指定位置，那么肯定要多一个参数来确定要从插入到顺序表的哪个位置。

![image-20260829220443806](C:\Users\sunny\AppData\Roaming\Typora\typora-user-images\image-20260829220443806.png)

比如要在下标为3的位置插入0，该怎么做呢？首先要把9,2往后挪，和上面的图一样。从下标5的位置开始往后挪动，因为如果直接区挪动9那么2就被覆盖掉了。所以，应该是pos位置以及pos之后的数据整体往后移动。既然是指定插入那么在插入前要看看见是否足够，而且顺序表的底层是数组，那么指定的位置`pos`肯定不能<0，因为没有这个下标，也不能超过现在的`size`有效的数据个数。如果只有两个数据，`size=2`那么可以在指定在2的位置插入吗？当然可以啦，因为如果两个数据`size=2`，那么2对应的是顺序表中下标2的位置呀，`[0,1,2]`

循环变量`i`该怎么取值？如果有两个数据：`[2,3]`，现在要把1插入到下标为0的位置，那么2,3挪动；`i=ps->size`开始挪动，当`i=pos`的时候就不需要再挪动了，因为当前的位置已经空出来了，所以是：`i>pos`



pos位置以及pos之后的数据整体往后移动后，就可以插入数据了，然后`size++`

```c
//  在指定位置之前插入
void SLInsert(SL* ps, int pos, int n)
{
	assert(ps && pos <= ps->size);

	// 空间是否足够
	SLCheckCapacity(ps);

	// pos位置以及pos之后的数据整体往后移动
	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = n;
	++(ps->size);
}
```



##### 3.5 删除指定位置的数据

```c
// 删除指定位置的数据
void SLDelete(SL* ps, int pos);
```

既然要删除指定位置的数据，那么`pos`肯定也不能<0，那么右区间呢？如果现在有两个数据`size=2`但是下标2是没有数据的，所以`pos<size`

该怎么删呢？假设现在的数据: `[3,4,5]`要把3删掉，也就是`pos=0`，其实只需要把`pos+1`以及后面的数据往前放就好了，直接覆盖掉原来的3。循环变量`i`该怎么取值呢？看图，首先第一个要把9往前挪动，第2次要把数据2往前挪，`size-1`不就是有效数据的最后一个数据吗？把这个数据往前挪动一位，那么`i`的最后一次挪动是在`size-2`

挪动完了之后，`ps->size--`

![image-20260829223048721](C:\Users\sunny\AppData\Roaming\Typora\typora-user-images\image-20260829223048721.png)

```c
// 删除指定位置的数据
void SLDelete(SL* ps, int pos)
{
	assert(ps && pos >= 0 && pos < ps->size	);
	
	// [3,4,5]
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	(ps->size)--;
}

```

删除的时候也可以`assert(ps->size)`因为如果顺序表里没有数据那就不用删了，但是这里也可以不加，因为`ps->size`如果为0，那么`pos`也为0，`assert`就不成立了



##### 3.6 顺序表的查找

```c
// 顺序表的查找
int SLFind(SL* ps, int n)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == n)
		{
			return i; // 返回数据所在的位置
		}
	}
	return -1; // 找不到
}
```



##### 3.7 顺序表输出

```c
// 输出
void SLPrint(const SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}
```



完整代码：

`SeqList.h`

```c
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 定义顺序表的结构


typedef int SeqListDataType;

// 动态顺序表
typedef struct SeqList
{
	int* arr;
	int size; // 当前顺序表有效数据的个数
	int capacity; // 当前顺序表空间大小
}SL;

// 顺序表初始化
void SLInit(SL* ps);

// 顺序表尾插
void SLPushBack(SL* ps, SeqListDataType n);

// 头插
void SLPushFront(SL* ps, SeqListDataType n);

// 尾删
void SLPopBack(SL* ps);
// 头删
void SLPopFront(SL* ps);

//  在指定位置之前插入
void SLInsert(SL* ps, int pos, int n);

// 删除指定位置的数据
void SLDelete(SL* ps, int pos);

// 顺序表的查找
int SLFind(SL* ps, int n);

// 输出数据
void SLPrint(SL* ps);

// 释放内存
void SLDestroy(SL* ps);
```



`SeqList.c`

```c
#include "SeqList.h"

// 顺序表初始化
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0; 
}


// 释放内存
void SLDestroy(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}




// 扩容空间
void SLCheckCapacity(SL* ps)
{
	// 空间是否足够
	if (ps->capacity == ps->size)
	{
		// 申请空间

		SeqListDataType newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SeqListDataType* tmp = (SeqListDataType*)realloc(ps->arr, newCapacity* sizeof(SeqListDataType));

		if (NULL == tmp)
		{
			// 申请失败
			perror("realloc");
			exit(1); // 退出程序
		}
		// 申请成功
		ps->arr = tmp;
		ps->capacity = newCapacity; // 更新空间容量大小
	}
}


// 尾插
void SLPushBack(SL* ps, SeqListDataType n)
{
	assert(ps);

	SLCheckCapacity(ps);
	// 插入数据
	ps->arr[(ps->size)++] = n;
}



// 头插
void SLPushFront(SL* ps, SeqListDataType n)
{
	assert(ps);

	SLCheckCapacity(ps);
	
	// 数据后移

	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}

	ps->arr[0] = n;
	(ps->size)++;

}



// 尾删
void SLPopBack(SL* ps)
{
	assert(ps && ps->size);
	--(ps->size);
}

// 头删
void SLPopFront(SL* ps)
{
	assert(ps && ps->size);

	for (int i = 0; i < ps->size-1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	--(ps->size);

}


//  在指定位置之前插入
void SLInsert(SL* ps, int pos, int n)
{
	assert(ps && pos >= 0 && pos <= ps->size);

	// 空间是否足够
	SLCheckCapacity(ps);

	// pos位置以及pos之后的数据整体往后移动
	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = n;
	++(ps->size);
}




// 删除指定位置的数据
void SLDelete(SL* ps, int pos)
{
	assert(ps && pos >= 0 && pos < ps->size	);
	
	// [3,4,5]
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	(ps->size)--;
}


// 顺序表的查找
int SLFind(SL* ps, int n)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == n)
		{
			return i; // 返回数据所在的位置
		}
	}

	return -1; // 找不到

}


// 输出
void SLPrint(const SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}


```



`test.c`

```c
#include "SeqList.h"


void test01()
{
	// 定义结构体变量
	SL sl;

	// 顺序表初始化
	SLInit(&sl);


	// 尾插
	SLPushBack(&sl, 6);
	SLPushBack(&sl, 7);
	SLPushBack(&sl, 8);
	SLPushBack(&sl, 9);
	SLPushBack(&sl, 10);
	printf("尾插: ");
	SLPrint(&sl); // 6 7 8 9 10
	printf("-----------------\n");

	// 头插
	SLPushFront(&sl, 5);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 1);

	printf("头插: ");
	SLPrint(&sl); // 1 2 3 4 5 6 7 8 9 10
	printf("-----------------\n");


	// 尾删
	SLPopBack(&sl);
	printf("尾删: ");
	SLPrint(&sl); // 1 2 3 4 5 6 7 8 9 10
	printf("-----------------\n");

	// 头删
	SLPopFront(&sl);
	printf("头删: ");
	SLPrint(&sl); // 2 3 4 5 6 7 8 9
	printf("-----------------\n");


	//  在指定位置之前插入
	SLInsert(&sl, 8, 1);
	printf("在指定位置之前插入： "); 
	SLPrint(&sl); //  2 3 4 5 6 7 8 9 1
	printf("-----------------\n");

	// 删除指定位置的数据
	SLDelete(&sl, 8);
	printf("指定删除数据： ");
	SLPrint(&sl); // 2 3 4 5 6 7 8 9 
	printf("-----------------\n");
	// 顺序表的查找
	int find = SLFind(&sl, 2);

	if (find>=0)
	{
		printf("找到了: %d\n", find);
	}
	else
	{
		printf("找不到\n");
	}

	// 释放内存
	SLDestroy(&sl);

}

int main()
{
	test01();

	return 0;
}
```

