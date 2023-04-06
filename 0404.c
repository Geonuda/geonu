#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE_STACK 100

#define FALSE 0
#define TRUE 1

typedef int element;
typedef struct {
    element stack[MAX_SIZE_STACK];
    int top;
}StackType;

void init(StackType *s){
    s->top = -1;
}

int is_empty(StackType *s){
    return s->top == -1;
}

int is_full(StackType *s){
    return s->top == MAX_SIZE_STACK -1;
}

void push(StackType *s, element item){
    if (is_full(s))
        exit(1);
    s->stack[++(s->top)] = item;
}

element pop(StackType *s){
    if (is_empty(s))
        exit(1);
    return s->stack[(s->top)--];
}

element peek(StackType *s){
    if (is_empty(s))
        exit(1);
    return s->stack[s->top];
}


int eval(char exp[]){
    int op1, op2, value, i;
    int len = (int) strlen(exp);
    char ch;
    StackType s;
    init(&s);
    for (i=0; i<len; i++) {
        ch = exp[i];
        

        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
            value = ch - '0';
            push(&s, value);
            continue;
        }
        
        op1 = pop(&s);
        op2 = pop(&s);
        
        switch (ch) {
            case '+': value = op1 + op2; break;
            case '-': value = op1 - op2; break;
            case '*': value = op1 * op2; break;
            case '/': value = op1 / op2; break;
            default: exit(1); break;
        }
        push(&s, value);
    }
    return pop(&s);
}

int main(){
    int result;
    char *postfix = "82/3-32*+";
    result = eval(postfix);
    printf("후위 표기식 %s의 계산 결과 : %d\n",postfix,result);
    return 0;
}
