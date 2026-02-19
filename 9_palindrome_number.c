#include "stdio.h"
#include "stdbool.h"
/*
Question :

Given an integer x, return true if x is a , and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

 

Constraints:

    -231 <= x <= 231 - 1


*/
bool isPalindrome(int x) {
    long long int sum = 0, num = x;
    if(x < 0) return false;
    else {
        while(x != 0) {
            int t = x%10;
            sum = sum*10 + t;
            x = x / 10;
        }
    }
    if(sum == num) return true;
    else return false;
}

int main() {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    if(isPalindrome(x)){
        printf("%d is a palindrome number\n", x);
    }
    else{
        printf("%d is not a palindrome number\n", x);
    }
    return 0;
}

/*
Output :

Enter a number: 121
121 is a palindrome number  

Enter a number: -121
-121 is not a palindrome number

*/