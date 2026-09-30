#include "queue.h"



// 检查队列是否为空
// 如果为空返回真，否则返回假
int IsEmpty(int* front, int* rear)
{
    if(-1 == *front && -1 == *rear)
        return 1; 
    else 
        return 0;
}


// 检查队列是否已满
// 如果满了返回真，否则返回假
int IsFull(int* rear)
{
    if(*rear == SIZE-1)
        return 1; 
    else
        return 0;
}

// 入队
void Enqueue(QueueType* queue, int* front, int* rear, QueueType val)
{
    // 检查队列是否为空
    if(IsEmpty(front, rear))
    {
        *front = 0;
        *rear = 0;
    }
    else if(IsFull(rear)) // 检查队列是否已满
    {
        printf("队列已满%d无加入队列\n", val);
        return;
    }
    else // 队列中有元素
    {
        (*rear)++;
    }
    // queue[*rear] = val; // 队尾插入元素
    *(queue + (*rear)) = val;
    
}

// 出队
void Dequeue(int* front, int* rear)
{
    // 检查队列是否为空
    if(IsEmpty(front, rear))
    {
        printf("队列中没有任何元素!\n");
        return;
    }
    else if((*front) == (*rear)) // 特殊情况：只有一个元素的时候front和rear相等
    {
        *front = -1;
        *rear = -1;
    }
    else
    {
        (*front)++;
    }
}


// 返回队首元素
QueueType* Front(int* queue, int* front, int* rear)
{

    // 检查队列是否为空
    if(IsEmpty(front, rear))
    {
        printf("队列为空!\n");
        return NULL;
    }

    // return queue[*front];
    return queue + (*front);
}