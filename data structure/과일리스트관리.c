#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void add_fruit(char *fruit, char fruit_list[][20], int *list_count, int max_count);
void delete_fruit(char *fruit, char fruit_list[][20], int *list_count, char deleted_fruits[][20], int *deleted_count);
void display_fruits(char fruit_list[][20], int list_count, char deleted_fruits[][20], int deleted_count);

int main() {
    char fruit_list[100][20] = {"Mango", "Orange", "Apple", "Grape", "Cherry", "Plum", "Guava", "Raspberry", "Banana", "Peach"};
    char deleted_fruits[100][20] = {0};
    int list_count = 10, deleted_count = 0, choice;
    char input_fruit[20];

    while(1) {
        printf("1. 추가\n2. 삭제\n3. 삭제된 과일 목록 출력\n4. 종료\n");
        printf("메뉴를 선택해주세요 : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("추가할 과일을 입력하세요 : ");
                scanf("%s", input_fruit);
                add_fruit(input_fruit, fruit_list, &list_count, 100);
                display_fruits(fruit_list, list_count, deleted_fruits, deleted_count);
                break;
            case 2:
                printf("삭제할 과일을 입력하세요 : ");
                scanf("%s", input_fruit);
                delete_fruit(input_fruit, fruit_list, &list_count, deleted_fruits, &deleted_count);
                display_fruits(fruit_list, list_count, deleted_fruits, deleted_count);
                break;
            case 3:
                display_fruits(fruit_list, list_count, deleted_fruits, deleted_count);
                break;
            case 4:
                printf("프로그램을 종료합니다.\n");
                return 0;
        }
    }
}

void add_fruit(char *fruit, char fruit_list[][20], int *list_count, int max_count) {
    for(int i = 0; i < *list_count; i++) {
        if (strcmp(fruit_list[i], fruit) == 0) {
            printf("%s은(는) 이미 존재합니다.\n", fruit);
            return;
        }
    }

    if(*list_count >= max_count) {
        printf("과일 목록이 가득 찼습니다.\n");
        return;
    }

    strcpy(fruit_list[*list_count], fruit); 
    (*list_count)++;
    printf("%s이(가) 추가되었습니다.\n", fruit);
}

void delete_fruit(char *fruit, char fruit_list[][20], int *list_count, char deleted_fruits[][20], int *deleted_count) {
    for(int i = 0; i < *list_count; i++) {
        if (strcmp(fruit_list[i], fruit) == 0) {
            strcpy(deleted_fruits[*deleted_count], fruit_list[i]);
            for(int j = i; j < *list_count - 1; j++) {
                strcpy(fruit_list[j], fruit_list[j+1]);
            }
            (*list_count)--;
            (*deleted_count)++;
            printf("%s이(가) 삭제되었습니다.\n", fruit);
            return;
        }
    }
    printf("해당하는 과일이 없습니다.\n");
}

void display_fruits(char fruit_list[][20], int list_count, char deleted_fruits[][20], int deleted_count) {
    printf("\n현재 과일 목록:\n");
    for(int i = 0; i < list_count; i++) {
        printf("%s -> ", fruit_list[i]);
        
    }
    printf("NULL");

    printf("\n삭제된 과일 목록:\n");
    for(int i = 0; i < deleted_count; i++) {
        printf("%s -> ", deleted_fruits[i]);
    }
    printf("NULL");
    printf("\n");
}

