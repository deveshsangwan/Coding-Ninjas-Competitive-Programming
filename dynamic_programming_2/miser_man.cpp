/*
Jack is a wise and miser man. Always tries to save his money.
One day, he wants to go from city A to city B. Between A and B, there are N number of cities(including B and excluding A) and in each city there are M buses numbered from 1 to M. And the fare of each bus is different. Means for all N*M busses, fare (K) may be different or same. Now Jack has to go from city A to city B following these conditions:
1. At every city, he has to change the bus.
2. And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.
You are to help Jack to go from A to B by spending the minimum amount of money.
N, M, K <= 100.
Input
Line 1:    N M

Line 2:    NxM Grid

Each row lists the fares the M busses to go form the current city to the next city.
Output
Single Line containing the minimum amount of fare that Jack has to give.
Sample Input
5 5
1  3  1  2  6
10 2  5  4  15
10 9  6  7  1
2  7  1  5  3
8  2  6  1  9
Sample Output
10
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    
    int dp[n][m];
    for(int i = 0; i < m; i++)
        dp[n - 1][i] = arr[n - 1][i];
    
    for(int i = n - 2; i >= 0; i--){
        dp[i][0] = arr[i][0] + min(dp[i + 1][0], dp[i + 1][1]);
        dp[i][m - 1] = arr[i][m - 1] + min(dp[i + 1][m - 2], dp[i + 1][m - 1]);
        for(int j = 1;j < m - 1; j++){
            dp[i][j] = arr[i][j] + min(dp[i + 1][j - 1], min(dp[i + 1][j], dp[i + 1][j + 1]));
        }
    }
    int k = INT_MAX;
    for(int i = 0; i < m; i++){
        k = min(k, dp[0][i]);
    }
    cout << k << endl;
    return 0;
}
