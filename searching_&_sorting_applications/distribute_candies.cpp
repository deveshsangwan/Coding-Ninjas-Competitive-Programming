/*Shaky has N (1<=N<=50000) candy boxes each of them contains a non-zero number of candies (between 1 and 1000000000). Shaky want to distibute these candies among his K (1<=K<=1000000000) IIIT-Delhi students. He want to distibute them in a way such that:
1. All students get equal number of candies.
2. All the candies which a student get must be from a single box only.
As he want to make all of them happy so he want to give as many candies as possible. Help Shaky in finding out what is the maximum number of candies which a student can get.
Input
First line contains 1<=T<=20 the number of test cases. Then T test cases follow. First line of each test case contains N and K. Next line contains N integers, ith of which is the number of candies in ith box.
Output
For each test case print the required answer in a seperate line.
Sample Input:
2
3 2 
3 1 4
4 1
3 2 3 9
Sample Output:
3
9*/
#include<bits/stdc++.h>
using namespace std;
int ans;

bool check(int *arr, int min, int max, int n, int k){
    int mid = (min + max)/2, person = 0;
    for(int i = 0; i < n; i++){
        person += arr[i]/mid;
        //cout << person << " " << k << endl;
        if(person >= k){
            return true;
        }
    }
    return false;
}

int binsDC(int *arr, int min, int max, int n, int k){
    int mid = (min + max)/2;
    if(mid == max || mid == min){
        //cout << "hi1" << endl;
        return ans;
    }
    if(check(arr, min, max, n, k)){
        if(mid > ans){
            //cout << "hi2" << endl;
            ans = mid;
        }
        //cout << "hi3" << endl;
        return binsDC(arr, mid, max, n, k);
    }
    else{
        //cout << "hi4" << endl;
    return binsDC(arr, min, mid, n, k);
    }
}

int main() {

	// Write your code here
    int t;
    cin >> t;
    while(t--){
        ans = 0;
        int n, k;
        cin >> n >> k;
        int arr[n];
        
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        
        cout << binsDC(arr, 0, *max_element(arr, arr + n), n, k) << endl;
    }
}