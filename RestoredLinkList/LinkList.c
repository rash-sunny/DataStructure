#include "LinkList.h"

// 创建节点
static Node* Create(ElementsType val)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    if(NULL == newNode)
    {
        perror("malloc");
        exit(1);
    }

    newNode->Data = val; 
    newNode->Next = NULL;

    return newNode;
    // 堆内存是可以返回的，栈内存不行
}


// 输出链表
void Print(Node* head)
{

    if(NULL == head)
    {
        printf("链表为空\n");
        return;
    }

    // printf("链表中数据: ");
    for(; head != NULL; head = head->Next)
    {
        printf("%d ", head->Data);
    }
    printf("\n");
}



// 头插节点
void InsertFront(Node** Phead, ElementsType val)
{
    assert(Phead);
    // 创建节点
    Node* temp = Create(val);
    temp->Next = *Phead;
    *Phead = temp;
}



// 头删
void DelFront(Node** Phead)
{
    // 防止传入NULL且链表不能为空
    assert(Phead != NULL && *Phead != NULL);

    // 记录当前头节点地址
    Node* del = *Phead;
    // 指向下一个节点
    *Phead = (*Phead)->Next;
    free(del);
}


// 统计链表中节点个数
static size_t GetNodeNum(Node* cur)
{
    size_t count = 0;
    // 遍历链表
    for(; cur != NULL; cur=cur->Next) 
    {
        count++;
    }    
    return count;
}

// 任意位置插入节点
void InsertPosNode(Node** Phead, ElementsType val , int pos)
{

    // 防止传入NULL
    assert(Phead);

    size_t cnt = GetNodeNum(*Phead);
   
    // 检查pos是否有效
    if(pos<1 || (size_t)pos > cnt + 1)
    {
        printf("插入的位置pos=%d无效,val=%d无法插入\n", pos, val); 
        return;
    }
    // 创建节点
    Node* newNode = Create(val);
    
    // 如果链表为空或插入位置是头节点,这里可以加上NULL == *Phead
    // 也可以不加，因为调用的时候必须要传递pos
    if(1 == pos)
    {
        newNode->Next = *Phead;
        *Phead = newNode;
        return;
    }

    // 往中间和尾巴插入
    Node* temp = *Phead; // 临时变量
    for(int i = 0; i < pos - 2; i++)
    {
        temp = temp -> Next; // 指向pos-1个节点
    }
    // 建立链接
    newNode->Next = temp->Next; // 待插入节点指向pos节点地址
    temp->Next = newNode; // pos-1节点指向待插入节点

}

// 删除任意位置节点
void DelPosNode(Node** Phead, int pos)
{
    // 空链表不能删,Phead也不能为空
    // 不能反着写，如果Phead=NULL，会段错误
    assert(Phead && *Phead);

    size_t cnt = GetNodeNum(*Phead);
    // 检查pos是否有效
    if(pos < 1 || (size_t)pos > cnt)
    {
        printf("删除的位置pos=%d无效,无法删除节点\n", pos); 
        return;
    }

    Node* temp1 = *Phead;
    // 删除头节点
    if(1 == pos)
    {
        *Phead = temp1->Next;
        free(temp1);
        return;
    }

    // 删除中间和尾节点
    for(int i = 0; i<pos-2; i++)
    {
        temp1 = temp1 ->Next; // 指向pos-1位置节点
    }
    Node* temp2 = temp1->Next; // 指向pos位置节点
    temp1->Next = temp2->Next; // pos-1指向pos+1节点
    free(temp2); // 释放堆内存 - 释放pos位置

}


// 释放链表
void DestroyList(Node** Phead)
{
    assert(Phead);
    Node* cur = *Phead;
    while(cur)
    {
        Node* next = cur->Next; // 下一个节点
        free(cur);
        cur = next;
    }
    *Phead = NULL;
}




/*


// 尾插节点
void InsertTail(Node** Phead, ElementsType val)
{
    // 如果实参传递的是NULL,assert会给出错误
    assert(Phead);

    Node* temp = Create(val); // 创建节点
    // 找尾
    for(; (*Phead) != NULL; Phead = &(*Phead)->Next) // Phead = &(*Phead)->Next 指向下一个链接口/节点
    {
        ;
    }
    *Phead = temp; 
    // 非空链表走到这里，*Phead已经不是头节点了。而是尾节点的Next字段，直接把temp值放进这个字段里
    // 空链表则是这就修改了实参的指向
   
}



// 尾删
void DelTail(Node** Phead)
{
    // 链表不能为空且头Phead也不能为空
    // 不能反着写，如果Phead=NULL，会段错误
    assert(Phead && *Phead);
    // 找尾节点
    for(;(*Phead)->Next != NULL; Phead = &(*Phead)->Next)
    {
        ;
    }
    free(*Phead);
    *Phead = NULL;
}


尾插和尾删这么写可读性并不高，还是用原来之前的写法更好阅读代码

*/


// 尾插
void InsertTail(Node** Phead, ElementsType val)
{
    // Phead不能为NULL
    assert(Phead);
    // 创建节点
    Node* newNode = Create(val);

    Node* tail = *Phead;

    // 空链表直接插入
    if(NULL == *Phead)
    {
        *Phead = newNode;
        return;
    }

    // 找到尾节点
    for(; tail->Next != NULL; tail = tail->Next)
    {
        ;
    }
    tail->Next = newNode;

}


// 尾删
void DelTail(Node** Phead)
{
    // Phead不能为NULL
    assert(Phead);

    // 空链表
    if(NULL == *Phead)
    {
        
        return;
    }

    // 只有一个节点
    if(NULL == (*Phead)->Next)
    {
        free(*Phead);
        *Phead = NULL;
        return;
    }

    Node* tail = *Phead;
    Node* temp = NULL;
    // 找尾
    for (; tail->Next != NULL; tail = tail->Next)
    {   
        // 尾节点的前一个节点
        temp = tail;
    }
    free(tail);
    temp->Next = NULL;
    
}
