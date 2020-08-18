/*
Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
Output
Output a single integer, maximum sum rectangle.
Constraints
1<=n,m<=100
Sample Input
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29
*/

#include<bits/stdc++.h>  
using namespace std;  

  
int kadane(int* arr, int* start, 
           int* finish, int n)  
{  
      
    int sum = 0, maxSum = INT_MIN, i;  
  
     
    *finish = -1;  
  
    int local_start = 0;  
  
    for (i = 0; i < n; ++i)  
    {  
        sum += arr[i];  
        if (sum < 0)  
        {  
            sum = 0;  
            local_start = i + 1;  
        }  
        else if (sum > maxSum)  
        {  
            maxSum = sum;  
            *start = local_start;  
            *finish = i;  
        }  
    }  
  
     
    if (*finish != -1)  
        return maxSum;  
  

    maxSum = arr[0];  
    *start = *finish = 0;  
    
    for (i = 1; i < n; i++)  
    {  
        if (arr[i] > maxSum)  
        {  
            maxSum = arr[i];  
            *start = *finish = i;  
        }  
    }  
    return maxSum;  
}  
  
 
 void findMaxSum(int **M, int ROW, int COL)  
{  
    int maxSum = INT_MIN, finalLeft, finalRight,  
                          finalTop, finalBottom;  
  
    int left, right, i;  
    int temp[ROW], sum, start, finish;  
  
     
    for (left = 0; left < COL; ++left)  
    {  
          
        memset(temp, 0, sizeof(temp));  
  
        for (right = left; right < COL; ++right)  
        {  
              
              
            for (i = 0; i < ROW; ++i)  
                temp[i] += M[i][right];  
  
              
            sum = kadane(temp, &start, &finish, ROW);  
  
            
            if (sum > maxSum)  
            {  
                maxSum = sum;  
                finalLeft = left;  
                finalRight = right;  
                finalTop = start;  
                finalBottom = finish;  
            }  
        }  
    }  
   
    cout << maxSum << endl;  
}  
  

int main()  
{
    int ROW, COL;
    cin >> ROW >> COL;
    int **M = new int*[ROW];
    for(int i = 0; i < ROW; i++)
        M[i] = new int[COL];
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            cin >> M[i][j];
        }
    }
  
    findMaxSum(M, ROW, COL);  
  
    return 0;  
} 