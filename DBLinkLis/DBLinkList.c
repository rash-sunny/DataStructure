// 双链表的实现

#include "DBLinkList.h"

// 创建节点
static Node* CreateNode(LinkListType val)
{
    // 申请空间创建节点
    Node* temp = (Node*)malloc(sizeof(Node));
    if(NULL == temp)
    {
        perror("malloc");
        exit(1);
    }
    
    // malloc申请空间成功
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    // 返回该节点地址
    return temp;
}


// 头插
Node* InsertAtHead(Node* head, LinkListType val)
{
    // 创建节点
    Node* newNode  = CreateNode(val);    

    // 空链表直接插入即可
    if(NULL == head)
    {
        return head = newNode;
    }

    // 非空链表
    head->prev = newNode; // 前一个节点地址
    newNode->next = head; // 下一个节点地址
    
    return head = newNode;
}

// 输出
void Print(Node* head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next; // 下一个节点
    }

    printf("\n");
}

// 反向输出
void ReversePrint(Node* head)
{ 
   
    // 找到链表最后一个节点
    Node* p = head;
    
    // 空链表,直接返回
    if(NULL == p)
    {
        return;
    }
    while(p->next != NULL)
    {
        p = p->next; // 下一个节点
    }  
    
    // 到达最后一个节点
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("\n");
}

// 尾插
Node* InsertAtTail(Node* head, LinkListType val)
{
    // 创建节点
    Node* newNode = CreateNode(val);

    // 特殊情况空链表
    if(NULL == head)
    {
       return head = newNode;
    }

    // 找到链表最后一个节点
    Node* p = head;
    while(p->next != NULL)
    {
        p = p->next; // 下一个节点
    }
    
    // 到达最后一个节点,建立链接
    p->next = newNode; // 链接新节点地址
    newNode->prev = p; // 链接前一个节点

    return head; 

}

// 头删
Node* PopHeadNode(Node* head)
{
    // assert(head);

    // 空链表
    if(NULL == head)
    {
        printf("空链表,没有节点可删\n");
        return head; // 没有节点,无需删直接返回即可
    }
    
    // 只有一个节点
    if(NULL == head->next)
    {
        free(head); // 直接释放
        return NULL;  // 返回空指针,这里不能返回head,因为该节点已经释放了,head就会变成野指针
    }
 
    Node* ptr = head;
    
    // 链表中多个节点
    head = ptr->next; // 头节点指向下一个节点
    head->prev = NULL; // 当前头节点的指针域prev置为空
    free(ptr); // 释放要删除的节点 

    return head;
}

// 尾删
Node* PopTailNode(Node* head)
{

    // 空链表
    // assert(head);  
    if(NULL == head)
    {
        printf("空链表,没有节点可删\n");
        return head; // 没有节点,无需删直接返回即可
    }   
       
    // 链表中只有一个节点
    if(NULL == head->next)
    {
        // 直接释放该节点
        free(head);
        return NULL; // 返回空指针,这里不能返回head,因为该节点已经释放了,head就会变成野指针
    }

    // 链表中有多个节点
    // 找到最后一个节点
    Node* ptr = head; // 临时变量
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    // 到达最后一个节点
    Node* temp = ptr->prev; // 前一个节点
    temp->next = NULL; // 成为最后一个节点
    free(ptr);
    return head;
}


static int GetNodeNum(Node* head)
{
    int cnt = 0;
    while(head != NULL)
    {
        cnt++;
        head=head->next;
    }
    return cnt;
}

// 删除任意位置节点
Node* DelPosNode(Node* head, int pos)
{
    // 检查pos是否有效位置
    size_t len = GetNodeNum(head);
    // assert(pos>=1 && pos <= len); 

    if(pos < 1 || pos > len)
    {
        printf("无效位置,无法删除\n");
        return head;
    }

    Node* cur = head; 

    // 找第pos个节点
    for(int i = 1; i < pos; i++)
    {
        cur = cur->next;
    }

    // 不是头节点
    if(cur->prev)
    {
        cur->prev->next = cur->next; // pos前一个节点的next字段,指向第pos+1节点
    }
    else
    {
        // 删头节点
        head = cur->next; // 如果链表中只有1个节点时,其prev&next都为空; 所以只有1个节点时执行这条语句最后head=NULL;
    }
    // 不是最后一个节点
    if(cur->next)
    {
        cur->next->prev = cur->prev; // 第pos+1个节点的prev,pos-1节点
    }

    // 释放pos位置节点
    free(cur);
    return head; 


    /*
        删除逻辑有3种情况: 删除头节点、删除尾节点、删除中间节点
        1.删除头节点，这很简单直接修改head指向pos+1个节点就好了.
        2.删除尾节点，尾巴节点的next字段一定是NULL;
        
        3. 删除中间节点，这个就要需要去修复指针的链接了。比如要删除第2个节点,那么就需要去修复前一个(第pos-1个节点)节点的next字段,
           以及第3个节（准确的说是第pos+1个节点）的prev字段
        
            第pos-1个节点的next字段要存放pos+1节点的地址,即为: cur->prev->next = cur->next;  
            cur指向当前节点,cur->prev这就是pos-1个节点;cur->prev->next这就拿到了next字段。
            现在链接好了pos-1节点next字段

            再来修复pos+1节点prev字段,也就是pos+1节点prev要存放pos-1节点的地址,即为: cur->next->prev = cur->prev;
            cur指向当前节点,cur->next这就是pos+1节点;cur->next->prev这就拿到了prev字段.它将存放pos-1节点的地址
            
        在回顾看尾删节点,next字段为空就是最后一个节点,但是它的prev字段不为空。所以就可以把这个操作划分给删中间节点操作;
        删除中间要修复两次链接对吧（next&prev）但是删尾节点只需要修复pos-1节点的next
        所以,cur->prev->next = cur->next; 这就把pos-1个节点的next该成了NULL，因为cur指向的是当前节点,如果当前节点是尾节点,cur->next为空

    */


}



Node* InsertPosNode(Node* head, int pos, LinkListType val)
{
    // 检查pos是否有效位置
    size_t len = GetNodeNum(head);
    // assert(pos>=1 && pos <= len+1); // 暴力
    if(pos < 1 || pos > len+1)
    {
        printf("插入无效位置,无法插入\n");
        return head; // 返回头节点
    }
    Node* newNode = CreateNode(val);

    Node* cur = head;
    
    if(NULL == head)
        return newNode;

    // 头插
    if(1 == pos)
    {
        cur->prev = newNode;
        newNode->next = cur;
        return newNode; // 新节点
    }


    // 找第pos个节点(中间插入)
    for(int i = 1; i<pos-1; i++)
    {
        cur = cur->next;
    }
    // 尾插
    if(NULL == cur->next)
    {
        // 建立链接(相当于是尾插了)
        cur->next = newNode; 
        newNode->prev = cur;
        return head;
    }
    newNode->next = cur->next; // 链接pos+1位置的节点
    cur->next->prev = newNode; // 改变pos+1节点的prev域的指向
    cur->next = newNode; // 改变当前节点next指向
    newNode->prev = cur; // prev指向当前节点

    return head;
}


// 反转链表
Node* Reverse(Node* head)
{
    
    // Node* next = NULL; // 记住节点中next字段
    // Node* cur = NULL; // 跟踪节点

    // while(head)
    // {
    //     cur = head; // 记住当前节点
    //     next = head->next;
    //     head->next = head->prev;
    //     head->prev = next;
    //     head = next;
    // }
 
    // return cur; // 返回当前节点


    // 简化代码
    Node* cur = NULL;
    while(head)
    {
        cur = head; // 记录当前节点
        head = head->next; // 下一个节点地址
        // 交换next和prev
        cur->next = cur->prev; 
        cur->prev = head;
    }
    return cur;


}