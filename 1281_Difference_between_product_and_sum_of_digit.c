/*
Given an integer number n, return the difference between the product of its digits and the sum of its digits.

Example 1:

Input: n = 234
Output: 15 
Explanation: 
Product of digits = 2 * 3 * 4 = 24 
Sum of digits = 2 + 3 + 4 = 9 
Result = 24 - 9 = 15

Example 2:

Input: n = 4421
Output: 21
Explanation: 
Product of digits = 4 * 4 * 2 * 1 = 32 
Sum of digits = 4 + 4 + 2 + 1 = 11 
Result = 32 - 11 = 21

 

Constraints:

    1 <= n <= 10^5

*/

#include "stdio.h"

int subtractProductAndSum(int n) {
    int p = 1;
    int s = 0;

    while(n > 0) {
        int digit = n % 10; 
        p = p * digit;
        s = s + digit;
        n = n / 10;          
    }

    return p - s;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int result = subtractProductAndSum(n);
    printf("The difference between product and sum of digits of %d is %d\n", n, result);
    return 0;
}

/*
Output :
Enter a number: 234
The difference between product and sum of digits of 234 is 15

Enter a number: 4421
The difference between product and sum of digits of 4421 is 21
*/