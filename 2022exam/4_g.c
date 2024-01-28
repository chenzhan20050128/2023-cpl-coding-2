#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_SIZE 2000 // 设置B值，为块的大小

// 定义块状链表的块结构
typedef struct Node
{
    int size;                // 记录当前块中元素的数量
    char str[MAX_NODE_SIZE]; // 存储块中的元素
    struct Node *next;       // 指向下一个块的指针
} Node;

// 定义块状链表的头指针和尾指针
Node *head = NULL, *tail = NULL;

// 定义一个在块状链表中插入字符串的函数
void insert(int pos, const char *t)
{
    Node *p = head; // p指针用来遍历链表
    int idx = 0;    // idx储存当前遍历的块中的元素数量
    // 遍历整个链表
    while (p != NULL)
    {
        // 如果遍历的块中元素数量小于目标位置，指针向后移
        if (idx + p->size < pos)
        {
            idx += p->size;
            p = p->next;
        }
        else
        {
            // 找到需要插入的块，并分裂这个块
            Node *node = (Node *)malloc(sizeof(Node));
            node->size = p->size - (pos - idx);
            memcpy(node->str, p->str + pos - idx, node->size);
            p->size = pos - idx;
            node->next = p->next;
            p->next = node;
            p = p->next;

            // 插入字符串
            // 字符串长度大于块大小，则需要多个块
            int len = strlen(t);
            for (int i = 0; i < len / MAX_NODE_SIZE; i++)
            {
                Node *node = (Node *)malloc(sizeof(Node));
                node->size = MAX_NODE_SIZE;
                memcpy(node->str, t + i * MAX_NODE_SIZE, node->size);
                node->next = p->next;
                p->next = node;
                p = node;
            }
            // 处理字符串剩下的部分
            node = (Node *)malloc(sizeof(Node));
            node->size = len % MAX_NODE_SIZE;
            memcpy(node->str, t + (len / MAX_NODE_SIZE) * MAX_NODE_SIZE, node->size);
            node->next = p->next;
            p->next = node;
            break;
        }
    }
}

// 定义一个查询指定位置字符的函数
char query(int pos)
{
    Node *p = head; // p指针用来遍历链表
    int idx = 0;    // idx储存当前遍历的块中的元素数量
    // 遍历整个链表
    while (p != NULL)
    {
        // 如果遍历的块中元素数量小于目标位置，指针向后移
        if (idx + p->size < pos)
        {
            idx += p->size;
            p = p->next;
        }
        else
        {
            // 找到目标位置对应的元素
            return p->str[pos - idx - 1];
        }
    }
    return '\0'; // 找不到对应位置返回空字符
}

// 定义一个根据初始字符串创建链表的函数
void createList(const char *s)
{
    int len = strlen(s); // 获取初始字符串长度
    // 创建链表并存入字符串，整个字符串长度大于块大小，则需要多个块
    for (int i = 0; i < len / MAX_NODE_SIZE; i++)
    {
        Node *node = (Node *)malloc(sizeof(Node));
        node->size = MAX_NODE_SIZE;
        memcpy(node->str, s + i * MAX_NODE_SIZE, node->size);
        node->next = NULL;
        if (head == NULL)
        { // 添加块到链表尾部
            head = tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }
    // 处理字符串剩下的部分
    Node *node = (Node *)malloc(sizeof(Node));
    node->size = len % MAX_NODE_SIZE;
    memcpy(node->str, s + (len / MAX_NODE_SIZE) * MAX_NODE_SIZE, node->size);
    node->next = NULL;
    if (head == NULL)
    { // 添加块到链表尾部
        head = tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
}

// 程序的主函数
int main()
{
    int n, q; // n是初始字符串长度，q是操作数量
    scanf("%d%d", &n, &q);
    char s[n + 1];

    // 输入初始字符串
    scanf("%s", s);

    // 根据初始字符串创建链表
    createList(s);

    // 执行操作
    while (q--)
    {
        char op[8], t[100001];
        int p;
        // 读取操作
        scanf("%s%d", op, &p);
        if (op[0] == 'Q')
        {
            // 查询操作
            printf("%c\n", query(p));
        }
        else
        {
            // 插入操作，输入插入的字符串然后插入
            scanf("%s", t);
            insert(p, t);
        }
    }
    return 0; // 程序结束
}