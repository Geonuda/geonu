#include <stdio.h>

void insert(int arr[], int num, int pos, int *size);
void delete(int arr[], int pos, int *size);
void display(int arr[], int size);

int main()
{
    int arr[100] = {0};
    int size = 0;
    int choice, num, pos;

    while (1)
    {
        printf("\n메뉴:\n(1) 리스트에 추가\n(2) 리스트에서 삭제\n(3) 리스트를 차례로 출력\n(0) 프로그램 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("추가할 숫자와 위치를 입력하세요: ");
            scanf("%d %d", &num, &pos);
            insert(arr, num, pos, &size);
            break;
        case 2:
            printf("삭제할 위치를 입력하세요: ");
            scanf("%d", &pos);
            delete(arr, pos, &size);
            break;
        case 3:
            display(arr, size);
            break;
        case 0:
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("올바른 입력이 아닙니다.\n");
        }
    }

    return 0;
}

void insert(int arr[], int num, int pos, int *size)
{
    int i;
    int ct = 0;

    for (i = *size; i > pos; i--)
    {
        arr[i] = arr[i - 1];
        ct++;
    }

    arr[pos] = num;
    *size += 1;

    printf("\n데이터 이동 횟수: %d\n", ct);
}

void delete(int arr[], int pos, int *size)
{
    int i;
    int ct = 0;

    for (i = pos; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
        ct++;
    }

    *size -= 1;

    printf("\n데이터 이동 횟수: %d\n", ct);
}

void display(int arr[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}
