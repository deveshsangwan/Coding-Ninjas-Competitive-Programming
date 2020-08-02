'''
Given an array of integers, print two integer values:
First, the sum of all numbers which are even as well as whose index are even.
Second, the sum of all numbers which are odd as well as whose index are odd.
Print the two integers space separated. (Arrays is 0-indexed)
Input:
Given an integer denoting the size of array.
Next line will have a line containing ‘n’ space separated integers.
Constraints:
1<=n<=10^5
1 <= Ai <= 10^6 
Output:
Two space separated integers denoting even and odd sums respectively.
Sample Input:
5
2 3 5 1 4
Sample Output:
6 4
'''
def even(x):
    if(x % 2 == 0):
        return True
    return False

# Write your code here
i = int(input())
arr = [int(x) for x in input().split()]
os, es = 0, 0
for j in range(i):
    if(even(j)):
        if(even(arr[j])):
            es += arr[j]
    else:
        if(even(arr[j]) == False):
            os += arr[j]
print(es, end = " ")
print(os)