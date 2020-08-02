'''
Ayush loves the characters ‘a’, ‘s’, and ‘p’. He got a string of lowercase letters and he wants to find out how many times characters ‘a’, ‘s’, and ‘p’ occurs in the string respectively. Help him find it out.
Input:
First line contains an integer denoting length of the string.
Next line contains the string.
Constraints:
1<=n<=10^5
‘a’<= each character of string <= ‘z’
Output:
Three space separated integers denoting the occurrence of letters ‘a’, ‘s’ and ‘p’ respectively.
Sample Input:
6
aabsas
Sample output:
3 2 0
'''
n = int(input())

str = input()

ca , cs, cp = 0, 0, 0 
for c in str:
    if c == 'a':
        ca += 1
    
    elif c == 's':
        cs += 1
    
    elif c == 'p':
        cp += 1

print(ca, end = " ")
print(cs, end = " ")
print(cp, end = " ")