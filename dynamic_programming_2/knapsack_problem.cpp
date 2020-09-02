/*
A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
Space complexity should be O(W).
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13
*/
#include<bits/stdc++.h>
int knapsack(int* weights, int* values, int n, int maxWeight){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */
   int dp[2][maxWeight + 1];
    for(int i = 0; i <= maxWeight; i++){
        dp[0][i] = 0;
    }
    
    int flag = 1;
    for(int i = 1; i <= n; i++){
        for(int w = 0; w <= maxWeight; w++){
                dp[flag][w] = dp[flag ^ 1][w];
            if(weights[i - 1] <= w){
                dp[flag][w] = max(dp[flag ^ 1][w], (values[i - 1] + dp[flag ^ 1][w - weights[i - 1]]));
            }
        }
        flag = flag ^ 1;
    }
   
    return dp[flag ^ 1][maxWeight];
}
