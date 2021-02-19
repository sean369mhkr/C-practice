#include<stdio.h>
int maxSubArray(int* nums, int numsSize) {
    int head;
    int tail;
    int sum;
    int max = nums[0];
    for (head = 0; head < numsSize; head++) {
        sum = 0;
        for (tail = head; tail < numsSize; tail++) {
            sum+=nums[tail];
            if (sum > max)
                max = sum;
        }
    }
    return max;
}
int main(int argc, char* argv[]) {
    int numsSize;
    printf("Input number of array : ");
    scanf_s("%d", &numsSize, 1);
    int *arr = malloc(numsSize * sizeof(int));
    if (!arr) {                      
        perror("Failed to allocate an array\n");   
    }                                                    
    for (int i = 0; i < numsSize; i++) {
        scanf_s("%d", &arr[i], 1);
    }   
    printf("The largest sum is %d\n", maxSubArray(arr,numsSize));
    return 0;
}