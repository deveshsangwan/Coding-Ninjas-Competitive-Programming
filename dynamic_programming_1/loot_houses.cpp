/*
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input Format
Line 1 : An integer N 
Line 2 : N spaced integers denoting money in each house
Output Format
 Line 1 : Maximum amount of money looted
Input Constraints
1 <= n <= 10^4
1 <= A[i] < 10^4
Sample Input :
6
5 5 10 100 10 5
Sample Output 1 :
110
*/
#include<bits/stdc++.h>
using namespace std;
int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
    if (n  == 1) return arr[0];

    int prev = arr[0];
    int curr = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++) {
        int temp = curr;
        curr = max(curr, prev + arr[i]);
        prev = temp;
    }
    return max(prev, curr);
}
