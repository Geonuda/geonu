#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node** head, int data, int position);
void delete(Node** head, int position);
void display(Node** head);

int main() {
    Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\n메뉴\n");
        printf("(1) 리스트에 추가\n");
        printf("(2) 리스트에서 삭제\n");
        printf("(3) 리스트를 차례로 출력\n");
        printf("(0) 프로그램 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("추가할 숫자와 위치를 입력하세요: ");
                scanf("%d %d", &data, &position);
                insert(&head, data, position);
                break;
            case 2:
                printf("삭제할 위치를 입력하세요: ");
                scanf("%d", &position);
                delete(&head, position);
                break;
            case 3:
                display(&head);
                break;
            case 0:
                exit(0);
            default:
                printf("잘못된 선택입니다. 다시 입력하세요.\n");
        }
    }

    return 0;
}

void insert(Node** head, int data, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    int count = 0;

    if (position == 0 || *head == NULL) {
        newNode->next = *head;
        *head = newNode;
        printf("이동 횟수: %d\n", count);
        return;
    }

    Node* current = *head;
    while (current != NULL && count < position - 1) {
        count++;
        current = current->next;
    }
    if (current == NULL) {
        printf("잘못된 위치입니다.\n");
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
    printf("이동 횟수: %d\n", count + 1);
}

void delete(Node** head, int position) {
    if (*head == NULL) {
        printf("리스트가 비어있습니다.\n");
        return;     
    }

    Node* temp = *head;
    int count = 0;

    if (position == 0) {
        *head = temp->next;
        free(temp);
        printf("이동 횟수: %d\n", count);
        return;
    }

    while (count < position - 1 && temp != NULL) {
        count++;
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("잘못된 위치입니다.\n");
        return;
    }

    Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
    printf("이동 횟수: %d\n", count + 1);
}

void display(Node** head) {
    if(*head == NULL) {
        printf("리스트가 비어있습니다.\n");
        return;
    }
    Node* temp = *head;
    printf("리스트: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
