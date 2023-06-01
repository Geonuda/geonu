#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NODE;

NODE *head = NULL;

void insert_beginning(int value) {
    NODE *new_node = (NODE *) malloc(sizeof(NODE));
    new_node->data = value;

    if (head == NULL) {
        head = new_node;
        new_node->next = head;
    } else {
        NODE *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        new_node->next = head;
        head = new_node;
        temp->next = head;
    }
}

void insert_end(int value) {
    NODE *new_node = (NODE *) malloc(sizeof(NODE));
    new_node->data = value;

    if (head == NULL) {
        head = new_node;
        new_node->next = head;
    } else {
        NODE *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        new_node->next = head;
        temp->next = new_node;
    }
}

void delete_beginning() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    } else {
        NODE *temp = head;
        NODE *last = head;

        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head;
        free(temp);
        printf("First node has been deleted.\n");
    }
}

void delete_end() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    } else {
        NODE *temp = head;
        NODE *prev = NULL;

        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        if (prev != NULL) {
            prev->next = head;
        } else {
            head = NULL;
        }
        free(temp);
        printf("Last node has been deleted.\n");
    }
}

void display_list() {
    if (head == NULL) {
        printf("List empty.\n\n");
        return;
    } else {
        NODE *temp = head;
        printf("List : ");
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n\n");
    }
}

int main() {
    int choice, value;

    do {
        printf("===== MENU =====\n");
        printf("(1) Insert First\n");
        printf("(2) Insert Last\n");
        printf("(3) Delete First\n");
        printf("(4) Delete Last\n");
        printf("(5) Print List\n");
        printf("(0) Exit\n");
        printf("Enter the menu: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Input a number: ");
                scanf("%d", &value);
                printf("\n");
                insert_beginning(value);
                break;
            case 2:
                printf("Input a number: ");
                scanf("%d", &value);
                printf("\n");
                insert_end(value);
                break;
            case 3:
                delete_beginning();
                printf("\n");
                break;
            case 4:
                delete_end();
                printf("\n");
                break;
            case 5:
                display_list();
                break;
            case 0:
                printf("Exit the program.\n");
                break;
            default:
                printf("Invalid selection. Please try again.\n\n");
        }
    } while (choice != 0);

    return 0;
}
