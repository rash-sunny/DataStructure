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