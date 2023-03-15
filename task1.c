#include <stdio.h>

int main(){
    int i = 0 , num = 0, sum = 0;

    for(num = 0; num <= 100; num++){
        for(i = 2; i < num; i++){
            if(num % i == 0)
            break;
        }
        if(num == i)
            sum = sum + num;
    }
    printf("%d", sum);
    printf("\n");

    return 0;
}