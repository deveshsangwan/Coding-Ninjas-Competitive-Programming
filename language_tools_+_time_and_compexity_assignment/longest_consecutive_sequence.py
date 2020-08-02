'''
You are given an array of unique integers that contain numbers in random order. Write a program to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains consecutive elements. Order of elements in the output is not important.
Best solution takes O(n) time.
If two sequences are of equal length then return the sequence starting with the number whose occurrence is earlier in the array.
Input Format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
0 <= n <= 10^8
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
Sample Output 1 :
8 
9 
10 
11 
12
Sample Input 2 :
7
3 7 2 1 9 8 41
Sample Output 2 :
7
8
9
Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but output should be [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array.
Sample Input 3 :
7
15 24 23 12 19 11 16
Sample Output 3 :
15 
16
'''
def longestConsecutiveSubsequence(l):
#Implement Your Code Here
#You have To Return the list of longestConsecutiveSubsequence
    ans = []
    #l.sort()
    maxlength = 0
    start = 0
    d = {}
    for i in range(len(l)):
        d[l[i]] = [1, True]
    
    #print(d)
    for i in range(len(l)):
        j = l[i]
        #print("hello")
        while(d[l[i]][1] == True):
            if j + 1 in d:
                d[l[i]][0] += 1
                j += 1
                #print("adhya")
            else:
                d[l[i]][1] = False
                
        if d[l[i]][0] > maxlength:
            maxlength = d[l[i]][0]
            start = l[i]
    #print(d)
    #print("max", maxlength)       
    for i in range(maxlength):
        #print("ilu")
        ans.append(start)
        start += 1
    return ans


n=int(input())
l=list(int(i) for i in input().strip().split(' '))
final = longestConsecutiveSubsequence(l)
for num in final:
    print(num)