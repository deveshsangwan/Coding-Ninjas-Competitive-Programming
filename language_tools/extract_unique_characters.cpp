/*
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
*/
#include<bits/stdc++.h>
char* uniqueChar(char *s){
	unordered_map<char, int> m1;
	
	char *arr=new char [50000];
	int j= 0;
	for (int i = 0; i < strlen(s); ++i)
	{
		m1[s[i]]++;
		if (m1[s[i]]==1)
		{
			arr[j] = s[i];
			j++;
		}

	}
	arr[j]='\0';
	return arr;

}