data = [[0, 0, -1, -1] for _ in range(10010)]  # Structure: 0: space, k 2^k; 1: id; 2: prev; 3: next;


def print_array(now_node_allo, head):
    print('---')
    for i in range(1, now_node_allo + 1):
        for j in range(4):
            print(data[i][j], end=' ')
        print()
    print(f'{head}---')


def num_bigger(num):
    num -= 1
    result = 0
    while num > 0:
        result += 1
        num //= 2
    return result


def main():
    n, q = map(int, input().strip().split())
    m = 1
    head = 1
    data[1][0] = n
    data[1][1] = 0
    data[1][2] = -1
    data[1][3] = -1
    now_node_allo = 1
    for _ in range(q):
        op = input().strip()
        if op == 'Q':
            head_now = head
            print(m)
            while data[head_now][3] != -1:
                print(data[head_now][1], end=' ')
                head_now = data[head_now][3]
            print(data[head_now][1], end=' ')
            print()
        elif op == 'A':
            id_now, space_now = map(int, input().strip().split())
            space_now = num_bigger(space_now)
            is_allocated = 0
            head_now = head
            while is_allocated == 0 and head_now != -1:
                if data[head_now][0] == space_now and data[head_now][1] == 0:
                    data[head_now][1] = id_now
                    is_allocated = 1
                elif data[head_now][0] > space_now and data[head_now][1] == 0:
                    while data[head_now][0] > space_now:
                        data[now_node_allo + 1][0] = data[head_now][0] - 1
                        data[now_node_allo + 1][1] = 0
                        data[now_node_allo + 1][2] = data[head_now][2]
                        data[now_node_allo + 1][3] = now_node_allo + 2
                        data[now_node_allo + 2][0] = data[head_now][0] - 1
                        data[now_node_allo + 2][1] = 0
                        data[now_node_allo + 2][2] = now_node_allo + 1
                        data[now_node_allo + 2][3] = data[head_now][3]

                        data[data[head_now][2]][3] = now_node_allo + 1
                        data[data[head_now][3]][2] = now_node_allo + 2
                        if head_now == head:
                            now_node_allo += 2
                            m += 1
                            head_now = now_node_allo - 1
                            head = head_now
                        else:
                            now_node_allo += 2
                            m += 1
                            head_now = now_node_allo - 1
                    data[head_now][1] = id_now
                    is_allocated = 1
                head_now = data[head_now][3]


if __name__ == "__main__":
    main()