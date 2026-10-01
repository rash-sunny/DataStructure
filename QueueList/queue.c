#include "queue.h"


// 入队
void Enqueue(Queue** front, Queue** rear, QueueType val)
{
    Queue* newNode = (Queue*)malloc(sizeof(Queue));
    if(NULL == newNode)
    {
        perror("malloc");
        return;
    }
    newNode->data = val;
    newNode->next = NULL;


    // 队列为空
    if(NULL == *front && NULL == *rear)
    {
        *front = *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    (*rear) = newNode;
}


// 出队
void Dequeue(Queue** front, Queue** rear)
{
    Queue* temp = *front;
    if(NULL == *front)
    {
        printf("队列中没有值可删!\n");
        return;
    }
    else if(*front == *rear) // 队列只有一个值
    {
        *front = *rear = NULL;
    }
    else
    {
        *front = (*front)->next;
    }
    free(temp);
}


// 返回队首元素
Queue* Front(Queue* front)
{
    if(NULL == front)
    {
        printf("没有队首\n");
    }
    return front;
}