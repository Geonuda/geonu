#include <stdio.h>
#define MAX_QUEUE_SIZE 5

int front = 0, rear = 0;
int queue[MAX_QUEUE_SIZE]; 

void insert(int data) { 
    if ((rear + 1) % MAX_QUEUE_SIZE == front) { 
        printf("Queue is full\n");
        return;
    }
    rear = (rear + 1) % MAX_QUEUE_SIZE; 
    queue[rear] = data;
}

int delete() {
    if (front == rear) { 
        printf("Queue is empty\n");
        return -1;
    }
    front = (front + 1) % MAX_QUEUE_SIZE; 
    return queue[front];
}

void printQueue() {
    printf("Queue: ");
    int i = (front + 1) % MAX_QUEUE_SIZE; 
    while (i != (rear + 1) % MAX_QUEUE_SIZE) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
    printf("\n");
}

int main() {
    int menu, data;
    while (1) {
        printf("Menu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print Queue\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &menu);
        switch (menu) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Deleted data: %d\n", delete());
                break;
            case 3:
                printQueue();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
