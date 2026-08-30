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
void SLPrint(const SL* ps);




// 释放内存
void SLDestroy(SL* ps);