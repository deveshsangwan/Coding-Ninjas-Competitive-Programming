/*
Gary is bored and wants to play an interesting but tough game . So he figured out a new board game called "destroy the neighbours" . In this game there are N integers on a board. In one move, he can pick any integer x from the board and then all the integers with value x+1 or x-1 gets destroyed .This move will give him x points.
He plays the game until the board becomes empty . But as he want show this game to his friend Steven, he wants to learn techniques to maximise the points to show off . Can you help Gary in finding out the maximum points he receive grab from the game ?
Input Format :
Line 1 : Integer N 
Line 2 : A list of N integers
Output Format :
Maximum points Gary can recieve from the Game setup
Constraints :
1<=N<=10^5
1<=A[i]<=1000
Sample Input :
2
1 2
Sample Output :
2
*/
#include<bits/stdc++.h>
using namespace std;
int solve(int n,vector<int>A){
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    int freq[1000];
    for(int i = 0; i < 1000; i++){
        freq[i] = 0;
        for(int j = 0; j < n; j++){
            if(i == A[j]){
                freq[i]++;
            }
        }
    }
    //cout << freq[1];
    
    int dp[1000];
    dp[0] = 0;
    dp[1] = freq[1];
    
    for(int i = 2; i < 1000; i++){
        dp[i] = max(dp[i - 2] + i * freq[i], dp[i - 1]);
    }
    return *max_element(dp, dp + 1000);
}