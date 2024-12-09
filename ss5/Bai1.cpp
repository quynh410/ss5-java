#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc một node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Hàm tạo một node mới
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Hàm thêm một node vào cuối danh sách
void append(Node** head, Node** tail, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) { // Danh sách rỗng
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

// Hàm duyệt danh sách từ cuối về đầu và in ra
void printReverse(Node* tail) {
    Node* temp = tail;

    // Duyệt từ cuối về đầu
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n"); // Kết thúc danh sách
}

// Hàm chính
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Input đầu tiên: 1 <-> 3 <-> 5 <-> 7
    append(&head, &tail, 1);
    append(&head, &tail, 3);
    append(&head, &tail, 5);
    append(&head, &tail, 7);

    // Output
    printf("Danh sách ngược lại: ");
    printReverse(tail);

    // Input thứ hai: 10 <-> 20
    head = tail = NULL; // Khởi tạo lại danh sách
    append(&head, &tail, 10);
    append(&head, &tail, 20);

    // Output
    printf("Danh sách ngược lại: ");
    printReverse(tail);

    return 0;
}
