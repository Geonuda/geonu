#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int top;
    int size;
} Stack;

void push(Stack *s, int num) {
    if (s->top == s->size - 1) {
        s->size *= 2;
        s->data = realloc(s->data, s->size * sizeof(int));
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
    Stack s = { .top = -1, .size = 1 };
    s.data = malloc(s.size * sizeof(int));
    int i;
    for (i = 1; i <= 30; i++) {
        int rand_num = rand() % 99+1;
        if (rand_num % 2 == 0) {
            push(&s, rand_num);
            printf("[%d] push %d\n",i, rand_num);
        } else {
            int pop_num = pop(&s);
            if (pop_num != -1) {
                printf("[%d] pop %d\n",i, pop_num);
            }
        }
    }
    free(s.data);
}