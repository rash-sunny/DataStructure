#include "queue.h"


void Print(QueueType* queue, int front, int rear)
{

    if(-1 == front && -1 == rear)
    {
        printf("队列为空!\n"); 
        return;
    }

    // [1][2][3]
    printf("队列中的元素: ");
    for(int i = front; i<=rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}



static void test01()
{
    int arr[10] = {0};
    
    // rear&fornt = -1 表示队列为空
    int rear = -1; // 队尾
    int front = -1; // 队首

    Enqueue(arr, &front, &rear, 2);
    Enqueue(arr, &front, &rear, 4);
    Enqueue(arr, &front, &rear, 6);
    Enqueue(arr, &front, &rear, 8);
    Print(arr, front, rear);

    // 移除队首元素
    Dequeue(&front,&rear);
    Dequeue(&front,&rear);
    Dequeue(&front,&rear);
    Dequeue(&front,&rear);
    Print(arr, front, rear);


    Enqueue(arr, &front, &rear, 2);
    QueueType* ret = Front(arr,&front, &rear);
    // printf("front=%d,rear%d\n", front, rear); //0,0
    if(ret != NULL)
    {
        printf("当前队列中队首的值为: %d\n", *ret);
    }


}

int main()
{
    test01();

    return 0;
}

