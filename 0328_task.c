#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int stack[MAX];
int top = -1;

void push(int data) {
    if (top >= MAX - 1) {
        
        return;
    }
    top++;
    stack[top] = data;
    printf("Push : %d\n", data);
}

int pop() {
    if (top < 0) {
        
        return -1;
    }
    int data = stack[top];
    top--;
    printf("Pop : %d\n", data);
    return data;
}

int main() {
   for (int i = 1; i <= 30; i++) {
      int rand_num = rand()%99+1;
      if (rand_num % 2 == 0) {
         push(rand_num);
         printf("[%d] push %d\n", i, rand_num);
      }
      else {
         printf("[%d] pop %d\n", i , pop());
      }
    }
   
    return 0;
}