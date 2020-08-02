'''
Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
Answer may not fit in integer . You have to take long.
Input
First line gives T, number of test cases.

2T lines follow.

First line gives you the number of stairs N

Next line gives you N numbers written on the stairs.
Output
For each test case output one line giving the final sum for each test case.
Constraints
T<=10

1<=N<=10^5

All numbers will be between 0 and 10^6.
Sample Input:
1
5
1 5 3 6 4
Sample Output:
15
Explanation:
For the first number, the contribution to the sum is 0.
For the second number, the contribution to the sum is 1.
For the third number, the contribution to the sum is 1.
For the fourth number, the contribution to the sum is 9 (1+5+3).
For the fifth number, the contribution to the sum is 4 (1+3).
Hence the sum is 15 (0+1+1+9+4).
'''
## Read input as specified in the question.
## Print output as specified in the question.
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
  
       
  
        if arr[i] < arr[j]: 
            temp_arr[k] = arr[i] 
            inv_count += (arr[i]*(right - j + 1))
            k += 1
            i += 1
        else: 
            temp_arr[k] = arr[j] 
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

t = int(input())
for i in range(t):
    n = int(input())
    arr = [int(x) for x in input().split()]
    print(mergeSort(arr, n))