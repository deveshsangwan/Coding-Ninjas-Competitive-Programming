/*
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/
#include <iostream>
#include <string>
using namespace std;


void print(int num, string output)
{   string s[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
 if(num == 0)
    {   cout<<output<<"\n";
        return;
    }   
 for(int k = 0;k<s[(num%10)-2].length();k++)
 {   
     print(num/10 ,s[(num%10)-2][k]+output);
 }
 
 
    
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    
    print(num,"");    
}
