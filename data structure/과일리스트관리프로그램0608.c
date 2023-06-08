#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
    char name[32];
    struct Node* prev;
    struct Node* next;
} Node;

void printMenu();
void printFruitList(Node* current);
Node* moveNext(Node* current);
Node* movePrev(Node* current);
Node* deleteCurrent(Node* current);
Node* insertNext(Node* current, char* name);

void printMenu() {
    printf("메뉴\n");
    printf("n) 다음 과일\n");
    printf("p) 이전 과일\n");
    printf("d) 현재 과일 삭제\n");
    printf("i) 현재일 다음에 과일 추가\n");
    printf("o) 과일 리스트 출력(현재 선택된 과일에는 마지막에 [O] 출력)\n");
    printf("e) 프로그램 종료\n");
}

void printFruitList(Node* current) {
    if (current == NULL) {
        printf("과일 리스트가 비어 있습니다.\n");
        return;
    }

    Node* firstNode = current;
    while (firstNode->prev != NULL) {
        firstNode = firstNode->prev;
    }

    while (firstNode != NULL) {
        printf("%s", firstNode->name);

        if (firstNode == current) {
            printf(" [O]");
        }

        printf("\n");
        firstNode = firstNode->next;
    }
}

Node* moveNext(Node* current) {
    if (current == NULL) {
        printf("과일 리스트가 비어 있습니다.\n");
    } else if (current->next == NULL) {
        printf("현재 과일이 마지막입니다.\n");
    } else {
        current = current->next;
    }
    return current;
}

Node* movePrev(Node* current) {
    if (current == NULL) {
        printf("과일 리스트가 비어 있습니다.\n");
    } 
    else if (current->prev == NULL) {
        printf("현재 과일이 첫 번째입니다.\n");
    }
    else {
        current = current->prev;
    }
    return current;
}

Node* deleteCurrent(Node* current) {
    if (current == NULL) {
        printf("과일 리스트가 비어 있습니다.\n");
        return NULL;
    }

    Node* nextNode = current->next;
    Node* prevNode = current->prev;

    if (nextNode != NULL) {
        nextNode->prev = prevNode;
    }

    if (prevNode != NULL) {
        prevNode->next = nextNode;
    }

    if (nextNode != NULL) {
        current = nextNode;
    } 
    else if (prevNode != NULL) {
        current = prevNode;
    } 
    else {
        current = NULL;
    }

    return current;
}

Node* insertNext(Node* current, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->prev = NULL;
    newNode->next = NULL;

    if (current == NULL) {
        current = newNode;
    } 
    else {
        newNode->next = current->next;
        newNode->prev = current;
        current->next = newNode;
        if (newNode->next != NULL) {
            newNode->next->prev = newNode;
        }
    }

    return current;
}

int main() {
    Node* fruitList = NULL;
    char command, fruitName[32];
    bool done = false;


    while (!done) {
        printf("\n");
        printMenu();
        printf("\n");
        printf("명령을 입력하세요: ");
        scanf(" %c", &command);

        switch (command) {
            case 'n':
                fruitList = moveNext(fruitList);
                break;
            case 'p':
                fruitList = movePrev(fruitList);
                break;
            case 'd':
                fruitList = deleteCurrent(fruitList);
                break;
            case 'i':
                printf("추가할 과일 이름: ");
                scanf("%s", fruitName);
                fruitList = insertNext(fruitList, fruitName);
                break;
            case 'o':
                printFruitList(fruitList);
                break;
            case 'e':
                printf("프로그램을 종료합니다.\n");
                done = true;
                break;
            default:
                printf("알 수 없는 명령입니다. 메뉴를 확인하세요.\n");
        }
    }
    
    return 0;
}
