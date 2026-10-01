#include "queue.h"


static void Print(Queue* front)
{
    if(NULL == front)
    {
        printf("队列为空!\n");
        return;
    }

    printf("队列中元素: ");
    for(; front != NULL; front = front->next)
        printf("%d ", front->data);
    printf("\n");
}


static void test01()
{
    Queue* front = NULL;
    Queue* rear = NULL;

    // 入队
    // Enqueue(&front, &rear, 2);
    // Enqueue(&front, &rear, 4);
    // Enqueue(&front, &rear, 7);

    // printf("front=%u, rear=%u\n", (unsigned int)front, (unsigned int)rear); // rear = 0

    // 出队
    // Dequeue(&front, &rear);
    
    // Print(front);


    // 入队
    Enqueue(&front, &rear, 2);
    Enqueue(&front, &rear, 4);
    Enqueue(&front, &rear, 5);
    Enqueue(&front, &rear, 8);

    Enqueue(&front, &rear, 6);
    Enqueue(&front, &rear, 1);
    Enqueue(&front, &rear, 3);
    Enqueue(&front, &rear, 7);
    Enqueue(&front, &rear, 9);
    Print(front);

    // 出队
    Dequeue(&front, &rear);
    Print(front);
    // 返回队首元素
    Queue* ret = Front(front);
    if(ret)
    {
        printf("队首是: %d", ret->data);
    }

}



int main()
{
    test01();
    return 0;
}