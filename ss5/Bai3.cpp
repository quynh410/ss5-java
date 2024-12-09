#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc node
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

// Hàm thêm node vào cuối danh sách
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

// Hàm xóa phần tử cuối cùng
void deleteLast(Node** head, Node** tail) {
    if (*head == NULL) { // Danh sách rỗng
        printf("Danh sách rỗng, không thể xóa.\n");
        return;
    }

    Node* temp = *tail;

    if (*head == *tail) { // Danh sách chỉ có một phần tử
        *head = *tail = NULL;
    } else {
        *tail = (*tail)->prev;
        (*tail)->next = NULL;
    }

    free(temp);
    printf("Phần tử cuối đã được xóa.\n");
}

// Hàm in danh sách
void printList(Node* head) {
    if (head == NULL) {
        printf("Danh sách rỗng.\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Hàm chính
int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int choice, value;

    do {
        // Menu lựa chọn
        printf("\n--- Menu ---\n");
        printf("1. Thêm phần tử vào cuối danh sách\n");
        printf("2. Xóa phần tử cuối cùng\n");
        printf("3. In danh sách\n");
        printf("4. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Thêm phần tử vào cuối
                printf("Nhập giá trị cần thêm: ");
                scanf("%d", &value);
                append(&head, &tail, value);
                printf("Phần tử đã được thêm vào danh sách.\n");
                break;

            case 2: // Xóa phần tử cuối cùng
                deleteLast(&head, &tail);
                break;

            case 3: // In danh sách
                printf("Danh sách hiện tại: ");
                printList(head);
                break;

            case 4: // Thoát
                printf("Thoát chương trình.\n");
                break;

            default:
                printf("Lựa chọn không hợp lệ. Vui lòng chọn lại.\n");
        }
    } while (choice != 4);

    return 0;
}