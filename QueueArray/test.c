#include "queue.h"


void Print(Queue* queue)
{

    if(-1 == queue->front && -1 == queue->rear)
    {
        printf("队列为空!\n"); 
        return;
    }

    // [1][2][3]
    printf("队列中的元素: ");
    for(int i = queue->front; i<=queue->rear; i++)
    {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}



// static void test01()
// {
//     int arr[10] = {0};
    
//     // rear&fornt = -1 表示队列为空
//     int rear = -1; // 队尾
//     int front = -1; // 队首

//     Enqueue(arr, &front, &rear, 2);
//     Enqueue(arr, &front, &rear, 4);
//     Enqueue(arr, &front, &rear, 6);
//     Enqueue(arr, &front, &rear, 8);
//     Print(arr, front, rear);

//     // 移除队首元素
//     Dequeue(&front,&rear);
//     Dequeue(&front,&rear);
//     Dequeue(&front,&rear);
//     Dequeue(&front,&rear);
//     Print(arr, front, rear);


//     Enqueue(arr, &front, &rear, 2);
//     QueueType* ret = Front(arr,&front, &rear);
//     // printf("front=%d,rear%d\n", front, rear); //0,0
//     if(ret != NULL)
//     {
//         printf("当前队列中队首的值为: %d\n", *ret);
//     }


// }



static void test02()
{
    Queue q = { 0 }; // 创建结构体变量
    q.front = -1;
    q.rear = -1;

    Enqueue(&q, 2);
    Print(&q);

    Dequeue(&q);
    Print(&q);


    Enqueue(&q, 2);
    Enqueue(&q, 5);
    Enqueue(&q, 3);
    Enqueue(&q, 9);
    Print(&q);

    Dequeue(&q);
    Dequeue(&q);
    
    Print(&q); // 3 9

    QueueType* ret = Front(&q);
    if(ret)
        printf("当前队列中队首的值为: %d\n", *ret); // 3
    
    
}


int main()
{
    // test01();

    test02(); // 测试封装成结构体

    return 0;
}


// 用结构体封装后，每个函数的参数都变得简洁了
// 注：Print函数不属于队列的操作，这里是为了方便我查看队列的每个操作是否正确