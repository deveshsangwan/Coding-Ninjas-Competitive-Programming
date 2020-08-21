/*
Given a n*m matrix which contains only 0s and 1s, find out the size of maximum square sub-matrix with all 0s. You need to return the size of square with all 0s.
Input format :
Line 1 : n and m (space separated positive integers)
Next n lines : m elements of each row (separated by space).
Output Format:
Line 1 : Size of maximum square sub-matrix
Sample Input :
3 3
1 1 0
1 1 1
1 1 1
Sample Output :
1
*/
#include<bits/stdc++.h>
using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    int dp[row][col];
    memset(dp, 0, row*col*sizeof(int));
    
    for(int i = 0; i < row; i++){
        if(arr[i][0] == 1){
            dp[i][0] = 0;
        }
        else{
            dp[i][0] = 1;
        }
    }
    
    for(int i = 0; i < col; i++){
        if(arr[0][i] == 1){
            dp[0][i] = 0;
        }
        else{
            dp[0][i] = 1;
        }
    }
    
    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            if(arr[i][j] == 1){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }
    
    /*for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }*/
    
    int maxElement = INT_MIN; 
    for (int i = 0; i < row; i++) { 
        for (int j = 0; j < col; j++) { 
            if (dp[i][j] > maxElement) { 
                maxElement = dp[i][j]; 
            } 
        } 
    }
    return maxElement;
}