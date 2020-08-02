/*
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 
*/
#include<iostream>
using namespace std;
void merge(int *arr, int st, int mid, int e){
    int i, j, k, temp[e - st + 1];
    i = st;
    j = mid + 1;
    k = 0;
    while(i <= mid && j <= e){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            //cout << "h1" << endl;
            i++;
        }
        else{
            temp[k] = arr[j];
            //cout << "h2" << endl;
            j++;
        }
        k++;
    }
    
    while(i <= mid){
        temp[k] = arr[i];
        //cout << "h3" << endl;
        i++;
        k++;
    }
    
    while(j <= e){
        temp[k] = arr[j];
        //cout << "h4" << endl;
        j++;
        k++;
    }
    
    
    for(i = st; i <= e; i++){
        arr[i] = temp[i - st];
    }
}

void mergeSort1(int *arr,int st,int e){
    if(st < e){
        int mid = (st + e)/2;
        mergeSort1(arr, st, mid);
        mergeSort1(arr, mid + 1, e);
        merge(arr, st, mid, e);
    }
}

void mergeSort(int input[], int size){
	// Write your code here
    int start = 0, end = size - 1;
    mergeSort1(input, start, end);
}
