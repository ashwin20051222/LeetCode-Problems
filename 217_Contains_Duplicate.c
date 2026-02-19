/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.

Example 2:

Input: nums = [1,2,3,4]

Output: false

Explanation:

All elements are distinct.

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]

Output: true

 

Constraints:

    1 <= nums.length <= 105
    -109 <= nums[i] <= 109


*/

#include "stdio.h"
#include "stdbool.h"

int compare (const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}
bool containsDuplicate(int* nums, int numsSize) {
    if (numsSize <= 1) return false;
    qsort(nums, numsSize, sizeof(int), compare);
    for(int i = 1; i < numsSize; i++) {
        if(nums[i] == nums[i-1]){
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int nums[n];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    bool result = containsDuplicate(nums, n);
    if(result) {
        printf("The array contains duplicates.\n");
    } else {
        printf("The array does not contain duplicates.\n");
    }
    return 0;
}

/*
Output :
Enter the number of elements: 4
Enter the elements: 1 2 3 1
The array contains duplicates.

Enter the number of elements: 4
Enter the elements: 1 2 3 4
The array does not contain duplicates.
*/