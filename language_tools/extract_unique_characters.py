'''
Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.
Input format :
String S
Output format :
Output String
Constraints :
0 <= Length of S <= 10^8
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde
'''
def uniqueChars(string):
    # Please add your code here
    str = string[0]
    for i in range(1, len(string)):
        bool = False
        for c in str:
            if string[i] == c:
                bool = True
        if bool == False:
            str += string[i]
    return str

# Main
string = input()
print(uniqueChars(string))
