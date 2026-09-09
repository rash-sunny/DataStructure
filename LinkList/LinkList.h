// 这是函数声明以及其它声明的文件

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LinkListType; // 重命名数据域类型，方便以后存储其它类型数据

// 定义节点
typedef struct Node
{
	LinkListType data; // 节点中数据域
	struct Node* next; // 链表中下一个节点的地址
}Node;



 //头插节点
Node* InsertFornt(Node* head, LinkListType val);

// 输出链表
void Print(Node* head);

// 尾插一个节点
Node* InsertBack(Node* head, LinkListType val);

// 任意位置插入一个节点
Node* InsertPosNode(Node* head, int pos, LinkListType val);


// 任意位置删除一个节点
Node* DelPosNode(Node* head, int pos);


// 反转链表
Node* Reverse(Node*head);
