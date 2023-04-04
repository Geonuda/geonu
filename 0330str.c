#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

typedef struct {
    int data[MAX];
    int top;
} Stack;

void push(Stack *s, int num) {
    if (s->top == MAX - 1) {
        printf("stack full.\n");
        return;
    }
    s->data[++(s->top)] = num;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("stack empty.\n");
        return -1;
    }
    return s->data[(s->top)--];
}

int main() {
    Stack s = { .top = -1 };
    int i;
    for (i = 1; i <= 30; i++) {
        int rand_num = rand() % 100;
        if (rand_num % 2 == 0) {
            push(&s, rand_num);
            printf("[%d] push %d\n",i, rand_num);
        } else {
            int popped_num = pop(&s);
            if (popped_num != -1) {
                printf("[%d] pop %d\n",i, popped_num);
            }
        }
    }
}