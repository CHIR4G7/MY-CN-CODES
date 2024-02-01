#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

char crossword[10][10];

bool isValidHorizontal(int row,int col,string word)
{
    if(10-col<word.length())
    {
        return false;
    }
    for(int i=0,j=col;i<word.length();++i,j++)
    {
        if(crossword[row][j]!='-' && crossword[row][j]!=word[j])
        {
            return false;
        }
    }
    return true;
}

bool isValidVertical(int row, int col, string word)
{
    if(10-row<word.length())
    {
        return false;
    }
    for(int i=row,j=0;i<word.length();++i,j++)
    {
        if(crossword[i][col]!='-' && crossword[i][col]!=word[j])
        {
            return false;
        }
    }
    return true;
}

void setHorizontal(int row,int col,string word)

bool crosswordHelper(string input[],int size,int index)
{
    if(index==size)
    {
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                cout << crossword[i][j];
            }
            cout << endl;
        }
        return true;
    }

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(crossword[i][j]=='-' || crossword[i][j]==input[index][0])
            {

            }
        }
    }
}

void solveCrossword(string input[],int size)
{
    bool result = crosswordHelper(input,size,0);
}
 
int main()
{
    //takng crossword as an input.
    string ss;
    for(int i=0;i<10;i++)
    {
        cin >> ss;
        for(int j=0;j<ss.size();j++)
        {
            crossword[i][j] = ss[j];
        }
    }

//taking the string input whhich will contain the words
    char s[200];
    cin >> s;

//making an array to store different words.
    string input[100];
    string word="";
    int a=0;//keep trck of the indecx
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]==';')
        {
            input[a++] = word;
            word = "";
        }
        else
        {
            word = word+s[i];
        }

    }
}