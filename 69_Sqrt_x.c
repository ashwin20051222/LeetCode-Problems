#include "stdio.h"

int squ(int x) {
    int i = 0;
    while (i * i <= x) { //Keep incrementing i until i*i is greater than x
        i++;
    }
    printf("The square root of %d is %d\n", x, i - 1);
    return i - 1;  // return the largest integer i such that i*i is less than or equal to x
}
int main() {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    squ(x);
    return 0;
}

/*
    Question : Given a non-negative integer x, compute and return the square root of x.
    The square root of x is the greatest integer that is less than or equal to the actual square root of x.

*/

/*
Output :
Enter a number: 16
The square root of 16 is 4  

Enter a number: 20
The square root of 20 is 4
*/