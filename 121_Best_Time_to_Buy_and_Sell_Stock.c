/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

 

Constraints:

    1 <= prices.length <= 105
    0 <= prices[i] <= 104


*/
#include "stdio.h"

int maxProfit(int* prices, int n) {
    int small = prices[0], max = 0;
    for(int i = 1; i < n; i++) {
        if(small > prices[i]) {
            small = prices[i];
        }
        int profit = prices[i] - small;
        if(profit > max) {
            max = profit;
        }
    }
    return max;
}

int main() {
    int n;
    printf("Enter the number of days: ");
    scanf("%d", &n);
    int prices[n];
    printf("Enter the stock prices for each day: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }
    int result = maxProfit(prices, n);
    printf("The maximum profit is: %d\n", result);
    return 0;
}

/*
Output :
Enter the number of days: 6
Enter the stock prices for each day: 7 1 5 3 6
The maximum profit is: 5

Enter the number of days: 5
Enter the stock prices for each day: 7 6 4 3 1
The maximum profit is: 0
*/