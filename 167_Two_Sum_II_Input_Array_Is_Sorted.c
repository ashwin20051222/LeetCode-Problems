/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers index1 and index2, each incremented by one, as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

 

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

*/
#include "stdio.h"
#include "stdlib.h"

int* twoSum(int* num, int numSize, int target, int* returnSize) {
    int left = 0, right = numSize-1;
    int *result = (int *)malloc(sizeof(int) * 2);
    while(left < right) {
        int sum = num[left] + num[right];

        if(sum == target) {
            result[0] = left + 1;
            result[1] = right + 1;
            *returnSize = 2;
            return result;
        }
        
        else if (sum > target) {
            right--;
        }

        else {
            left++;
        }
    }
    return NULL;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *num = (int *)malloc(sizeof(int) * n);
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    int target;
    printf("Enter the target: ");
    scanf("%d", &target);
    int returnSize;
    int *result = twoSum(num, n, target, &returnSize);
    if(result != NULL) {
        printf("Indices of the two numbers: [%d, %d]\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found.\n");
    }
    free(num);
    return 0;
}

/*
Output :

Enter the size of the array: 4
Enter the elements of the array: 2 7 11 15
Enter the target: 9
Indices of the two numbers: [1, 2]  
*/