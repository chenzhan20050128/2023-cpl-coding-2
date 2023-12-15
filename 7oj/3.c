#include <stdio.h>
#include <string.h>
#include <math.h>

int data[10010][4]; // structure:0:space,k 2^k;1:id;2:prev;3:next;
void print_array(int now_node_allo, int head)
{
    printf("---\n");
    for (int i = 1; i <= now_node_allo; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
    printf("%d---\n", head);
}
int num_bigger(int num)
{
    num = num - 1;
    int result = 0;
    while (num > 0)
    {
        result += 1;
        num /= 2;
    }
    return result;
}

int main()
{
    int n;
    int q;
    scanf("%d %d", &n, &q);
    int m = 1; // 空间链结点的总数.
    char op;
    int id_now;
    int space_now;
    int head = 1;
    data[1][0] = n;
    data[1][1] = 0;
    data[1][2] = -1;
    data[1][3] = -1; //-1 means not exist
    int now_node_allo = 1;
    for (int i = 1; i <= q; i++)
    {
        getchar();
        scanf("%c", &op);
        // printf("%c\n", op);
        if (op == 'Q')
        {
            int head_now = head;
            printf("%d\n", m);
            while (data[head_now][3] != -1)
            {
                printf("%d ", data[head_now][1]); // print id of each node;
                head_now = data[head_now][3];
            }
            printf("%d ", data[head_now][1]);
            printf("\n");
        }
        else if (op == 'A')
        {
            scanf("%d %d", &id_now, &space_now);
            space_now = num_bigger(space_now);
            int is_allocated = 0;
            int head_now = head;
            while (is_allocated == 0 && head_now != -1)
            {
                if (data[head_now][0] == space_now && data[head_now][1] == 0)
                {
                    data[head_now][1] = id_now;
                    is_allocated = 1;
                }
                else if (data[head_now][0] > space_now && data[head_now][1] == 0)
                {
                    while (data[head_now][0] > space_now)
                    {
                        data[now_node_allo + 1][0] = data[head_now][0] - 1;
                        data[now_node_allo + 1][1] = 0;
                        data[now_node_allo + 1][2] = data[head_now][2];
                        data[now_node_allo + 1][3] = now_node_allo + 2;
                        data[now_node_allo + 2][0] = data[head_now][0] - 1;
                        data[now_node_allo + 2][1] = 0;
                        data[now_node_allo + 2][2] = now_node_allo + 1;
                        data[now_node_allo + 2][3] = data[head_now][3];

                        data[data[head_now][2]][3] = now_node_allo + 1;
                        data[data[head_now][3]][2] = now_node_allo + 2;
                        if (head_now == head)
                        {
                            now_node_allo += 2;
                            m += 1;
                            head_now = now_node_allo - 1;
                            head = head_now;
                        }
                        else
                        {
                            now_node_allo += 2;
                            m += 1;
                            head_now = now_node_allo - 1; //-2+1 come back to 65;
                        }
                    }
                    data[head_now][1] = id_now;
                    is_allocated = 1;
                }
                head_now = data[head_now][3];
            }
            // print_array(now_node_allo, head);
        }
        else
        {
            // printf("error");
        }
    }

    return 0;
}