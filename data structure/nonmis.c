#include <stdio.h>

typedef struct Stackinfo{
    unsigned int count;
    unsigned int size;
    int *p_data;
} STACK;

void Push(int a_num, STACK *ap_stack){
    if(ap_stack->count<ap_stack->count){
        *(ap_stack->p_data+ap_stack->count)=a_num;
        ap_stack->count++;
    }else printf("stack이 가득차서 값을 넣을 수 없습니다.");
}

int Pop(int *ap_num, STACK *ap_stack){
    if(ap_stack->count==0){
        printf("stack에 저장된 값이 없습니다.");
        return 0;
    }
    ap_stack->count--;
    *ap_num=*(ap_stack->p_data+ap_stack->count);
    return 1;
}

void Showstack(STACK *ap_stack){
    int i;

    if(ap_stack->count==0) printf("stack에 저장된 값이 없습니다,\n");
    else{
        printf("stack에 저장된 값 목록\n");
        for(i=0; i<ap_stack->count;i++){
            printf("[%03d] : %d\n", i+1, *(ap_stack->p_data+1));
        }
        printf("총 %d개의 값이 저장되어 있습니다.\n",ap_stack->count);
    }
}