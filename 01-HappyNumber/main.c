#include<stdio.h>
#include<stdbool.h>
int mulnum(int n) {
    int reint = 0;
    while (n > 0) {
        reint += (n % 10)*(n % 10);
        n /= 10;
    }
    return reint;
}

bool isHappy(int n) {
    int fast = n;
    int slow = n;
    do {
        slow = mulnum(slow);
        fast = mulnum(fast);
        fast = mulnum(fast);
    } while (slow != fast);
    return fast==1;
}

int main(int argc, char* argv[]) {
    int i;
    if (argc == 1) {
        printf("Input a Number : ");
        scanf_s("%d", &i, 1);
    }
    else
        i = atoi(argv[1]);

    if(isHappy(i))
        printf("%d is Happy number\n", i);
    else
        printf("%d isn't Happy number\n", i);
    return 0;
}