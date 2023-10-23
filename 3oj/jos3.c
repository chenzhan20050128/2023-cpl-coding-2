#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;


int josephusSurvivor(int n, int k) {
    if (n == 1) {
        return 1;  // 只剩下一个人，直接返回编号1
    }

    Node* head = (Node*)malloc(sizeof(Node));
    Node* prev = head;
    
    // 构建循环链表
    for (int i = 1; i <= n; i++) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = i;
        prev->next = new_node;
        prev = new_node;
    }
    
    prev->next = head; // 链接链表成环
    Node* current = head;
    Node* previous = prev;
    
    while (current != current->next) {
        for (int i = 0; i < k - 1; i++) {
            previous = current;
            current = current->next;
        }
        
        previous->next = current->next;
        printf("%d ",current->data);
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    int survivor = current->data;
    
    free(current);
    return survivor;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
   
    int lastSurvivor = josephusSurvivor(n, k);
    printf("%d\n", lastSurvivor);
    
    return 0;
}
