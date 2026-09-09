#define _CRT_SECURE_NO_WARNINGS 1

#include "LinkList.h"
// 这是测试链表的文件


static void test01()
{
	Node* head = NULL; // 空链表

	// 头插节点
	//head = InsertFornt(head, 5);
	//head = InsertFornt(head, 7);
	//head = InsertFornt(head, 6);
	//Print(head);

	// 尾插一个节点
	//head = InsertBack(head, 7);
	//head = InsertBack(head, 5);
	//head = InsertBack(head, 9);
	//Print(head); // 7 5 9
	//head = InsertPosNode(head, 3, 8); // 7 5 8 9
	//head = InsertPosNode(head, 1, 6); // 6 7 5 8 9

	head = InsertBack(head, 7);
	head = InsertBack(head, 5);
	head = InsertBack(head, 8);
	head = InsertBack(head, 9);
	Print(head);

	head = DelPosNode(head, 3);
	Print(head);
	//head = DelPosNode(head, 2);
	//Print(head);
	// head = DelPosNode(head, 1);
	// Print(head);
	// head = DelPosNode(head, 1);
	// Print(head);
	// head = DelPosNode(head, 1);
	// Print(head);

	head = Reverse(head);
	Print(head); // 9 5 7 

}



static void test02()
{
	Node* head = NULL;

	printf("头插: ");
	head = InsertFornt(head, 1);
	head = InsertFornt(head, 2);
	head = InsertFornt(head, 3);
	Print(head);
	printf("\n");
	
	printf("尾插: ");
	head = InsertBack(head, 0);
	head = InsertBack(head, -1);
	Print(head);
	printf("\n");


	printf("任意位置插入节点: ");
	head = InsertPosNode(head, 1, 4); // 插入头节点 4 3 2 1 0 -1
	head = InsertPosNode(head, 7, -2); // 4 3 2 1 0 -1 -2
	//head = InsertPosNode(head, 0, 10);
	//head = InsertPosNode(head, 11, 10);
	Print(head);
	printf("\n");


	printf("任意位置删除节点: ");
	head = DelPosNode(head, 7);; // 4 3 2 1 0 -1
	head = DelPosNode(head, 1);; // 3 2 1 0 -1
	Print(head);
	printf("\n");


	printf("反转链表: ");
	head = Reverse(head); // -1 0 1 2 3
	Print(head);
	printf("\n");

}




int main()
{
	//test01();
	test02();

	return 0;
}

// 任意位置插入节点，还没有判断插入的是否为有效位置
// 任意位置删除节点，还没有判断删除的是否为有效位置
