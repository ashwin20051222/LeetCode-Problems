/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:

Input: nums = [0]
Output: [0]

 

Constraints:

    1 <= nums.length <= 104
    -231 <= nums[i] <= 231 - 1

*/

#include "stdio.h"

void moveZeroes(int* nums, int numsSize) {
    int n = 0;
    for(int j = 0; j < numsSize; j++){
        if(nums[j] != 0){
            nums[n] = nums[j];
            n++;
        }
    }
    while(n < numsSize){
        nums[n] = 0;
        n++;
    }
}

int main() {
    int numsSize;
    printf("Enter the size of the array: ");
    scanf("%d", &numsSize);
    int nums[numsSize];
    printf("Enter the elements: ");
    for(int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }
    moveZeroes(nums, numsSize);
    printf("Output: [");
    for(int i = 0; i < numsSize; i++) {
        printf("%d", nums[i]);
        if(i < numsSize - 1) {
            printf(",");
        }
    }
    printf("]\n");
    return 0;
}

/*
Output :
Enter the size of the array: 5
Enter the elements: 0 1 0 3 12
Output: [1,3,12,0,0]

Enter the size of the array: 1
Enter the elements: 0
Output: [0]
*/