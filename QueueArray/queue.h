#include <stdio.h>


#define SIZE 10

typedef int QueueType;

// 封装成结构体，可以简洁点
typedef struct
{
    QueueType arr[SIZE];
    int front;
    int rear;
}Queue;


// 入队
void Enqueue(Queue* queue, QueueType val);

// 出队
void Dequeue(Queue* queue);


// 返回队首元素
QueueType* Front(Queue* queue);

// 检查队列是否为空
int IsEmpty(Queue* queue);


// 检查队列是否已满
int IsFull(Queue* queue);