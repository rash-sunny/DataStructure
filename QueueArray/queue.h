#include <stdio.h>


#define SIZE 10

typedef int QueueType;

// 入队
void Enqueue(QueueType* queue, int* front, int* rear, QueueType val);

// 出队
void Dequeue(int* front, int* rear);


// 返回队首元素
QueueType* Front(int* queue, int* front, int* rear);

// 检查队列是否为空
int IsEmpty(int* front, int* rear);


// 检查队列是否已满
int IsFull(int* rear);