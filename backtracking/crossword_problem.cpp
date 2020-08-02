/*
CodingNinjas has provided a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
Note: We have provided such test cases that there is only one solution for the given input.
Input format:
The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
The next line of input contains the word list, in which each word is separated by ';'. 
Output format:
Print the crossword grid, after placing the words of word list in '-' cells.  
Sample Test Cases:
Sample Input 1:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Sample Output 1:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
*/
#include<bits/stdc++.h>
using namespace std;

void printSolution(char cross[][10])
{
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) 
            cout << cross[i][j] << "";
    	cout << endl;
    }
}
bool isValidVertical(char cross[][10],string s,int row,int col)
{
	int i=row;
    while((cross[i][col]=='-' || s[i-row]==cross[i][col]) && (i-row)<s.length() )
        i++;
    if((i-row)<s.length())
        return false;
    else
        return true;
    
}
bool isValidHorizontal(char cross[][10],string s,int row,int col)
{
	int j=col;
    while((cross[row][j]=='-' || s[j-col]==cross[row][j]) && (j-col)<s.length() )
        j++;
    if((j-col)<s.length())
        return false;
    else
        return true;
}
void setVertical(char cross[][10],string s,int row,int col,bool filled[])
{
    int i=row,count=0;
    while(count!=s.length())
    {
        if(cross[i][col]=='-') {
            filled[count]=true;
            cross[i][col] = s[count];
        }
        i++;
        count++;
    }
}
void setHorizontal(char cross[][10],string s,int row,int col,bool filled[])
{
    int j=col,count=0;
    while(count!=s.length())
    {
        if(cross[row][j]=='-') {
            filled[count]=true;
            cross[row][j] = s[count];
        }
        j++;
        count++;
    }
}
void resetVertical(char cross[][10],string s,int row,int col,bool filled[])
{
    int i=row,count=0;
	while(count!=s.length())
    {
        if(filled[count]==true)
            cross[i][col]='-';
        i++;
        count++;
    }
}
void resetHorizontal(char cross[][10],string s,int row,int col,bool filled[])
{
    int j=col,count=0;
	while(count!=s.length())
    {
        if(filled[count]==true)
            cross[row][j]='-';
        j++;
        count++;
    }
}
bool crossWord(char cross[][10],vector<string> words,int index)
{
    if(index==words.size())
    {
        printSolution(cross);
        return true;
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(cross[i][j]=='-' || cross[i][j]==words[index][0])
            {
                if(isValidVertical(cross,words[index],i,j))
                {
                    int len = words[index].length();
                    bool filled[len];
                    for(int i=0;i<len;i++)
                        filled[i] = false;
                    setVertical(cross,words[index],i,j,filled);
                    bool recV = crossWord(cross,words,index+1);
                    if(!recV)
                    //crossWord(cross,words,index+1);
                    	resetVertical(cross,words[index],i,j,filled);
                }
                else if(isValidHorizontal(cross,words[index],i,j))
                {
					int len = words[index].length();
                    bool filled[len];
                    for(int i=0;i<len;i++)
                        filled[i] = false;
                    setHorizontal(cross,words[index],i,j,filled);
                    bool recH = crossWord(cross,words,index+1);
                    if(!recH)
                    //crossWord(cross,words,index+1);
                    	resetHorizontal(cross,words[index],i,j,filled);
                }
            }                        
                    
        }
    }
    return false;

} 
int main() {

	// Write your code here
    char cross[10][10];
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            cin >> cross[i][j];
    
    string str;
    cin >> str;
    
   
    vector<string> words;
    int i=0;
   	while(str[i]!='\0')
    {
        string a ="";
        while(str[i]!='\0' && str[i]!=';')
            a+=str[i++];
        i++;
        words.push_back(a);
    } 

  
    crossWord(cross,words,0);    
    
    
    

} 