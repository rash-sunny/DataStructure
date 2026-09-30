#include "queue.h"

// 检查队列是否为空
// 如果为空返回真，否则返回假
int IsEmpty(Queue* queue)
{
    if(-1 == queue->front && -1 == queue->rear)
        return 1; 
    else 
        return 0;
}


// 检查队列是否已满
// 如果满了返回真，否则返回假
int IsFull(Queue* queue)
{
    if(queue->rear == SIZE-1)
        return 1; 
    else
        return 0;
}

// 入队
void Enqueue(Queue* queue, QueueType val)
{
    // 检查队列是否为空
    if(IsEmpty(queue))
    {
        queue->front = 0;
        queue->rear = 0;

    }
    else if(IsFull(queue)) // 检查队列是否已满
    {
        printf("队列已满%d无加入队列\n", val);
        return;
    }
    else // 队列中有元素
    {
        queue->rear =  (queue->rear)+1;
    }
    queue->arr[queue->rear] = val;
    
}

// 出队
void Dequeue(Queue* queue)
{
    // 检查队列是否为空
    if(IsEmpty(queue))
    {
        printf("队列中没有任何元素!\n");
        return;
    }
    else if(queue->front == queue->rear) // 特殊情况：只有一个元素的时候front和rear相等
    {
        queue->front = -1;
        queue->rear = -1;
    }
    else
    {
        // queue->front += 1;
        queue->front = (queue->front) + 1;
    }
}


// 返回队首元素
QueueType* Front(Queue* queue)
{

    // 检查队列是否为空
    if(IsEmpty(queue))
    {
        printf("队列为空!\n");
        return NULL;
    }

    return (queue->arr) + (queue->front);
}