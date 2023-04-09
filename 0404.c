#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int top;
    int data[MAX_STACK_SIZE];
} Stack;

void push(Stack *s, int value) {
    if (s->top < MAX_STACK_SIZE - 1) {
        s->top++;
        s->data[s->top] = value;
    } else {
        printf("Stack overflow!");
        exit(1);
    }
}

int pop(Stack *s) {
    if (s->top >= 0) {
        int value = s->data[s->top];
        s->top--;
        return value;
    } else {
        printf("Stack underflow!");
        exit(1);
    }
}

int main() {
    char input[MAX_STACK_SIZE];
    int i, value, a, b;
    Stack s = { .top = -1 };

    printf("Enter postfix expression: ");
    scanf("%s", input);

    for (i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            push(&s, input[i] - '0');
        } else {
            b = pop(&s);
            a = pop(&s);
            switch (input[i]) {
                case '+':
                    value = a + b;
                    break;
                case '-':
                    value = a - b;
                    break;
                case '*':
                    value = a * b;
                    break;
                case '/':
                    value = a / b;
                    break;
            }
            push(&s, value);
        }
    }

    printf("Result: %d\n", pop(&s));

    return 0;
}
