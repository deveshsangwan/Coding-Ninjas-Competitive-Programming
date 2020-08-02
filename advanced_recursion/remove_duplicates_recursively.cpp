/*
Given a string S, remove consecutive duplicates from it recursively.
Input Format :
String S
Output Format :
Output string
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string
Sample Input 1 :
aabccba
Sample Output 1 :
abcba
Sample Input 2 :
xxxyyyzwwzzz
Sample Output 2 :
xyzwz
*/
#include<cstring>
void removeConsecutiveDuplicates1(char *input, int i){
    int l = strlen(input);
    if(input[i] == '\0')
        return;
    
    while(input[i] == input[i + 1]){
        int j;
        for(j = i; j < l - 1; j++){
            input[j] = input[j + 1];
        }
        input[j] = '\0';
    }
    removeConsecutiveDuplicates1(input, i + 1);
}

void removeConsecutiveDuplicates(char *input) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/
    removeConsecutiveDuplicates1(input, 0);
}