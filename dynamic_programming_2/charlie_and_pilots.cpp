/*
Charlie acquired airline transport company and to stay in business he needs to lower the expenses by any means possible. There are N pilots working for his company (N is even) and N/2 plane crews needs to be made. A plane crew consists of two pilots - a captain and his assistant. A captain must be older than his assistant. Each pilot has a contract granting him two possible salaries - one as a captain and the other as an assistant. A captain's salary is larger than assistant's for the same pilot. However, it is possible that an assistant has larger salary than his captain. Write a program that will compute the minimal amount of money Charlie needs to give for the pilots' salaries if he decides to spend some time to make the optimal (i.e. the cheapest) arrangement of pilots in crews.
Input
The first line of input contains integer N, 2 ≤ N ≤ 10,000, N is even, the number of pilots working for the Charlie's company. The next N lines of input contain pilots' salaries. The lines are sorted by pilot's age, the salaries of the youngest pilot are given the first. Each of those N lines contains two integers separated by a space character, X i Y, 1 ≤ Y < X ≤ 100,000, a salary as a captain (X) and a salary as an assistant (Y).
Output
The first and only line of output should contain the minimal amount of money Charlie needs to give for the pilots' salaries. 
Sample Input
4 
5000 3000 
6000 2000 
8000 1000 
9000 6000 
Sample Output
19000 
*/
#include <bits/stdc++.h> 
#define MAX 10001 
using namespace std; 
int memo[MAX][MAX/2+2], n, A[2][MAX]; 

int solve(int a, int c, int cur){ 
    if(memo[cur][a]!=0) 
        return memo[cur][a]; 
    if(a==n/2){ 
        int ans=0, x=cur; 
        while(x<=n){ 
            ans+=A[0][x++]; 
        } 
        return memo[cur][a]=ans; 
    } 
    if(a==c){ 
        return memo[cur][a]=A[1][cur]+solve(a+1, c, cur+1); 
    } 
    else if(a>c){ 
        return memo[cur][a]=min(A[1][cur]+solve(a+1, c, cur+1), A[0][cur]+solve(a, c+1, cur+1)); 
    } 
    else 
    return 0; 
} 


int main(){ 
    int i; 
    cin>>n; 
    for(i=0;i<n;i++){ 
        cin>>A[0][i]; 
        cin>>A[1][i]; 
    } 
    cout<<solve(0, 0, 0); 
}