#include<stdio.h>

int SingleNumber(int* nums, int numsSize) {
    int n = nums[0];
    for (int i = 1; i < numsSize; i++) {
        n^=nums[i];            //XOR
    }
    return n;
}

int main(int argc, char* argv[])
{   

    int arr[10];
    int InputSize;
    InputSize = argc - 1;
    if ((InputSize == 0) || (InputSize > 9)) {
        printf("Input the size of number : ");
        scanf_s("%d", &InputSize, 1);
        if (InputSize > 10) {
            InputSize = 10;
        }
        else if (InputSize < 1) {
            InputSize = 1;
        }
        for (int i = 1; i <= InputSize; i++) {
            scanf_s("%d", &arr[i - 1], 1);
        }
    }
    else {
        for (int i = 1; i <= InputSize; i++) {
            arr[i - 1] = atoi(argv[i]);
        }
    }
    
    printf("Input Size %d\n", InputSize);

    printf("Single No. is %d", SingleNumber(arr, InputSize));
    return 0;
}

