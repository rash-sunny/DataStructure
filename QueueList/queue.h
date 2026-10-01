#include <stdio.h>
#include <stdlib.h>

typedef int QueueType;

// 声明节点
typedef struct Node
{
    QueueType data;
    struct Node* next;
}Queue;


// 入队
void Enqueue(Queue** front, Queue** rear, QueueType val);

// 出队
void Dequeue(Queue** front, Queue** rear);

// 返回队首元素
Queue* Front(Queue* front);