#include <iostream>
using namespace std;

bool checkPalindrome(char str[])
{
    int len = strlen(str);

    if(len==0)
    {
        return true;
    }

    char temp[len + 1];
    for (int i = 0; i <= (len); i++)
    {
        temp[i] = str[len - 1 - i];
    }

    if (strcmp(temp, str) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
        
    
}
 
int main()
{
     int size = 1e6;
    char str[size];
    cin >> str;
    cout << (checkPalindrome(str) ? "true" : "false");

}