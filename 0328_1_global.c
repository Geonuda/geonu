#include <stdio.h>
#define MAX 10

int stack[MAX];
int data_count = 0;

void Push(int a_num){
    if(data_count < MAX){
        stack[data_count] = a_num;
        data_count++;
    }else printf("stack이 가득찼습니다.\n");
}

int Pop(int *ap_num){
    if(data_count == 0){
        printf("stack에 저장된 값이 없습니다.\n");
        return 0;
    }
    data_count--;
    *ap_num = stack[data_count];
    return 1;
}

void showstack(){
    int i;
    if(data_count ==0)printf("stack에 저장된 값이 없습니다.\n");
    else{
        printf("stack에 저장된 값 목록\n");
        for(i=0; i < data_count; i++){
            printf("[%03d] : %d\n", i+1,stack[i]);
        }
        printf("총 %d개의 값이 저장되어 있습니다.\n",data_count);
    }
}

int main(void){
    int select_index =  0, temp=0;
    while(select_index !=4){
        printf("\n\n1. Stack 값 넣기\n");
        printf("2. stack에서 값 꺼내기\n");
        printf("3. stack에 저장된 값 확인\n");
        printf("4. 프로그램 종료\n\n");
        printf("선택 : ");
        scanf("%d", &select_index);

        switch(select_index){
            case 1:
                printf("저장할 값 입력 : ");
                scanf("%d", &temp);
                Push(temp);
                break;
            case 2:
                if(Pop(&temp)) printf("가져온 값 > %d", temp);
                break;
            case 3:
                showstack();
                break;
        }
    }
    return 0;
}