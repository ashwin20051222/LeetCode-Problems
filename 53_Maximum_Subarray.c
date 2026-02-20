/*
Given an integer array nums, find the with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

 

Constraints:

    1 <= nums.length <= 105
    -104 <= nums[i] <= 104

*/

#include <stdio.h>

int maxSubArray(int* arr, int n) {
    int prefix = 0;
    int min = 0;
    int max = arr[0];

    for(int i = 0; i < n; i++) {
        prefix += arr[i];
        if(prefix - min > max) {
            max = prefix - min;
        }
        if(prefix < min) {
            min = prefix;
        }
    }
    return max;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int result = maxSubArray(arr, n);
    printf("The largest sum of a contiguous subarray is: %d\n", result);
    return 0;
}   

/*
Output :
Enter the size of the array: 9
Enter the elements of the array: -2 1 -3 4 -1 2 1 -5 4
The largest sum of a contiguous subarray is: 6  

Enter the size of the array: 1
Enter the elements of the array: 1
The largest sum of a contiguous subarray is: 1

Enter the size of the array: 5
Enter the elements of the array: 5 4 -1 7 8
The largest sum of a contiguous subarray is: 23
*/