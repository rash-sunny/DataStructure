#include "queue.h"


void Print(Queue* queue)
{

    if(-1 == queue->front && -1 == queue->rear)
    {
        printf("队列为空!\n"); 
        return;
    }

    printf("当前队列: ");
    for(int i = queue->front; ; i = (i+1) % SIZE)
    {
        printf("%d ", queue->arr[i]); // 打印到队尾
        if(i == queue->rear)
            break;
    }
    printf("\n");
}


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

    // printf("front%d, rear=%d\n", q.front, q.rear); // 测试当前front和rear在哪个位置
    // 入队
    Enqueue(&q, 2);
    Enqueue(&q, 5);
    Enqueue(&q, 6);
    Enqueue(&q, 8);
    Enqueue(&q, 1);
    Enqueue(&q, 4);
    Print(&q);

    ret = Front(&q);
    if(ret)
        printf("当前队列中队首的值为: %d\n", *ret); // 3

    // 当前队列已经满了来看看rear的位置是不是SIZE-1的位置
    printf("front=%d, rear=%d\n", q.front, q.rear); // 2, 9


    // 再次入队会发生什么？
    Enqueue(&q, 7); // 队列已满7无加入队列


    // 但是front=2 也就是说arr[0],arr[1]这两个位置浪费掉了，该怎么办？
    // 于是就有了循环数组或说叫循环队列
    
    // 循环数组就是到达了数组最大下标的位置，然后又回到下标0 就像星期日到星期一
}




static void test03()
{
    Queue q = { 0 };

    // 空队列
    q.front = -1;
    q.rear = -1;


    // 入队
    Enqueue(&q, 2);
    Enqueue(&q, 4);
    Enqueue(&q, 6);
    Enqueue(&q, 8);
    Enqueue(&q, 10);
    Enqueue(&q, 3);
    Enqueue(&q, 5);
    Enqueue(&q, 7);
    Enqueue(&q, 9);
    Enqueue(&q, 0);
    Print(&q);
    
    // 出队
    Dequeue(&q);
    Dequeue(&q);
    // printf("front=%d, rear=%d\n", q.front, q.rear);
    Print(&q);
    QueueType* ret = Front(&q);
    if(ret)
        printf("当前队列中队首的值为: %d\n", *ret); // 6

    // printf("front=%d, rear=%d\n", q.front, q.rear);

    // // 再来插入
    Enqueue(&q, 1);
    Enqueue(&q, 2);

    Print(&q);
    printf("front=%d, rear=%d\n", q.front, q.rear);

    Enqueue(&q, 20); // 队列已经满

    // Dequeue(NULL);  // 测试为空
}


int main()
{
    // test01();

    // test02(); // 测试封装成结构体

    test03(); // 循环数组

    return 0;
}


// 用结构体封装后，每个函数的参数都变得简洁了
// 注：Print函数不属于队列的操作，这里是为了方便我查看队列的每个操作是否正确


// 这里使用的是循环数组，解决了front左边的空间浪费问题