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

