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

// Hàm chèn phần tử vào vị trí bất kỳ
void insertAtPosition(Node** head, Node** tail, int data, int position) {
    Node* newNode = createNode(data);

    if (position == 0) { // Chèn ở đầu danh sách
        newNode->next = *head;
        if (*head) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        if (*tail == NULL) { // Nếu danh sách ban đầu rỗng
            *tail = newNode;
        }
        return;
    }

    Node* temp = *head;
    int index = 0;

    // Duyệt đến vị trí cần chèn
    while (temp != NULL && index < position - 1) {
        temp = temp->next;
        index++;
    }

    if (temp == NULL) { // Vị trí không hợp lệ
        printf("Lỗi: Vị trí không hợp lệ\n");
        free(newNode);
        return;
    }

    // Chèn vào giữa hoặc cuối
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next) {
        temp->next->prev = newNode;
    } else { // Nếu chèn ở cuối
        *tail = newNode;
    }
    temp->next = newNode;
}

// Hàm in danh sách
void printList(Node* head) {
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
    int choice, value, position;

    do {
        // Menu lựa chọn
        printf("\n--- Menu ---\n");
        printf("1. Thêm phần tử vào cuối danh sách\n");
        printf("2. Chèn phần tử vào vị trí bất kỳ\n");
        printf("3. In danh sách\n");
        printf("4. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Thêm phần tử vào cuối
                printf("Nhập giá trị cần thêm: ");
                scanf("%d", &value);
                append(&head, &tail, value);
                printf("Phần tử đã được thêm vào cuối danh sách.\n");
                break;

            case 2: // Chèn phần tử vào vị trí bất kỳ
                printf("Nhập giá trị cần chèn: ");
                scanf("%d", &value);
                printf("Nhập vị trí cần chèn: ");
                scanf("%d", &position);
                insertAtPosition(&head, &tail, value, position);
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
