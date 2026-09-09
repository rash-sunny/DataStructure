// 这是链表每个方法的实现

#include "LinkList.h"


// 创建节点
static Node* CreateNode(LinkListType val)
{
    // 创建节点
    Node* temp = (Node*)malloc(sizeof(Node));
    // 判断是malloc是否申请成功
    if (NULL == temp)
    {
        perror("malloc");
        exit(1);
    }

    temp->data = val; // 设置节点数据域为val
    temp->next = NULL; // 节点指针域为空
    
    return temp; // 返回该节点
}


// 统计当前链表有多少个节点
static int GetNodeNum(Node* head)
{
    int cnt = 0;
    while (head != NULL) // 这样就不会少数了
    {
        cnt++;
        head = head->next;
    }

    // 最后一个节点
    return cnt;
}


// 头插节点
Node* InsertFornt(Node* head, LinkListType val)
{
    // 创建节点
    Node* node = CreateNode(val);
    node->next = head; // 指向下一个节点或者空

    // 注: node->next = head; 是属于尾插逻辑，如果放到CreateNode就不对了。
    // CrateNode的唯一目标就是创建节点且每个节点的指针域都为空，数据域该是什么就是什么了

    head = node; // 链表不再为空,而是指向该节点

    return head;
}


// 输出链表
void Print(Node* head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next; // 下一个节点的地址
    }
    printf("\n");
}



// 尾插一个节点
Node* InsertBack(Node* head, LinkListType val)
{
    // 创建节点
    Node* node = CreateNode(val);

    // 如果链表为空直接插入
    if (head == NULL)
    {
        head = node;
        return head;
    }

    // 找到链表中节点的末尾
    Node* tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next; // 下一个节点
    }
    // 找到了链表末尾，插入节点
    tail->next = node; // 修改当前链表最后一个节点的指针域为要插入的节点地址

    return head;
}



// 任意位置插入一个节点
Node* InsertPosNode(Node* head, int pos, LinkListType val)
{
    // 判断插入位置是否有效
    if (pos <= 0)
    {
        printf("无效位置\n");
        return head;
    }


    // 当前链表节点的个数
    int len = GetNodeNum(head);

    // 如果要插入的位置超过了右区间有效位置,直接尾插
    if (pos > len)
    {
       return InsertBack(head, val);
        
    }

    // 创建节点
    Node* node = CreateNode(val);
    if (1 == pos)
    {
        //node->next = head; // 插入节点的指针域存放之前头节点的地址
        //head = node; // head指向插入的节点
        //return head;

        // 头插
        return InsertFornt(head, val);

    }

    Node* temp = head; // 临时指针变量


    // 中间
    // 找到要插入的位置pos
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    // 到达要插入的位置
    node->next = temp->next; // 待插入节点的指针域存放pos节点的地址
    temp->next = node; // n-1个节点的指针域存放待插入节点的地址

    return head;
}

// 任意位置删除一个节点
Node* DelPosNode(Node* head, int pos)
{
    //assert(head); // 链表不为空
    if (NULL == head)
    {
        printf("链表为空，无法删除任何节点\n");
        return NULL;
    }
    
    if (pos <= 0)
    {
        printf("无效位置,无法删除\n");
        return head;
    }

    int count = GetNodeNum(head);
    if (pos > count)
    {
        printf("无效位置,无法删除\n");
        return head;
    }


    Node* temp1 = head;
    Node* temp2 = temp1->next; 

    // 删除头节点特殊处理
    if (1 == pos)
    {
        head = temp2;
        free(temp1);
        return head;
    }

    for (int i = 1; i<pos-1; i++)
    {
        temp1 = temp1->next; // 删除前的一个节点
        temp2 = temp1->next; // 删除节点的后一个节点
    }

    //printf("temp1=%d\n", temp1->data);
    //printf("temp2=%d\n", temp2->data);

    temp1->next = temp2->next; // 连接节点
    free(temp2); // 释放节点

    return head;
}


// 反转链表
//Node* Reverse(Node* head)
//{
//
//    if (NULL == head)
//    {
//        printf("链表为空，无法反转\n");
//        return NULL;
//    }
//
//    Node* current = head; // 当前节点
//    Node* next = NULL; // 前一个节点的地址
//    Node* pre = NULL; // 刚开始头节点指针域为NULL;
//    // 遍历链表 找到末尾
//    while (current != NULL)
//    {
//        next = current->next; // 存放下一个节点
//        current->next = pre; // 修改当前节点指针域指向
//        pre = current; // 保存前一个节点地址
//        current = next; // 来到下一个节点
//    }
//
//    // 到达链表末尾,此时per里存放是：末尾节点的前一个节点地址
//    //current->next = pre;
//
//    //head = current; // 修改头节点的指向
//
//    //return head;
//    return pre;
//
//}





Node* Reverse(Node* head)
{
    Node* current = head; // 当前节点
    Node* next = NULL; // 记录下一个几点的地址
    Node* pre = NULL; // 当前节点要的值

    // 循环一直到链表末尾
    while (current)
    {
        next = current->next; // 记录下一个节点的地址
        current->next = pre; //  给当前节点赋值
        pre = current; // 当前节点赋值
        current = next; // 到达下一个节点
    }
    return pre; // 返回新头
}
