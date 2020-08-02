'''
Given an integer array of size 2N + 1. In this given array, N numbers are present twice and one number is present only once in the array.
You need to find and return that number which is unique in the array.
Note : Given array will always contain odd number of elements.
Input format :
Line 1 : Array size i.e. 2N+1
Line 2 : Array elements (separated by space)
Output Format :
Unique element present in the array
Constraints :
1 <= N <= 10^6
Sample Input :
7
2 3 1 6 3 6 2
Sample Output :
1
'''
def FindUnique(arr):
    # Please add your code here
    arr.sort()
    if(arr[0] != arr[1]):
        return arr[0]

    elif(arr[len(arr) - 2] != arr[len(arr) - 1]):
        return arr[len(arr) - 1]

    for i in range(2, len(arr) - 2):
        if(arr[i] != arr[i + 1] and arr[i] != arr[i - 1]):
            return arr[i]

# Main
n=int(input())
arr=list(int(i) for i in input().strip().split(' '))
unique=FindUnique(arr)
print(unique)
