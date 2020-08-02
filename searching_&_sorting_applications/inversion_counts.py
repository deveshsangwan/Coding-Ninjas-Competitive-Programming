'''
Let A[0 ... n-1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A (where i and j are indexes of A). Given an integer array A, your task is to find the number of inversions in A.
Input format :
Line 1 : n, array size
Line 2 : Array elements (separated by space).
Output format :
Count of inversions
Constraints :
1 <= n <= 10^5
1 <= A[i] <= 10^9
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Sample Input 2 :
5
2 5 1 3 4
Sample Output 1 :
4
'''
## Read input as specified in the question.
## Print output as specified in the question.
def mergeSort(arr, n): 
    temp_arr = [0]*n 
    return _mergeSort(arr, temp_arr, 0, n-1) 
  
def _mergeSort(arr, temp_arr, left, right):  
  
    inv_count = 0 
  
    if left < right: 
  
        mid = (left + right)//2
        inv_count = _mergeSort(arr, temp_arr, left, mid) 
        inv_count += _mergeSort(arr, temp_arr, mid + 1, right) 
        inv_count += merge(arr, temp_arr, left, mid, right) 
    return inv_count 

def merge(arr, temp_arr, left, mid, right): 
    i = left      
    j = mid + 1  
    k = left 
    inv_count = 0
 
    while i <= mid and j <= right: 
  
       
  
        if arr[i] <= arr[j]: 
            temp_arr[k] = arr[i] 
            k += 1
            i += 1
        else: 
       
            temp_arr[k] = arr[j] 
            inv_count += (mid-i + 1) 
            k += 1
            j += 1
   
    while i <= mid: 
        temp_arr[k] = arr[i] 
        k += 1
        i += 1
  
    while j <= right: 
        temp_arr[k] = arr[j] 
        k += 1
        j += 1
  
    for loop_var in range(left, right + 1): 
        arr[loop_var] = temp_arr[loop_var] 
          
    return inv_count

n = int(input())
arr = [int(x) for x in input().split()]
print(mergeSort(arr, n))
