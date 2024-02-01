#include <iostream>
using namespace std;

string keys[] = {" ", " ", "abc", "def", "ghi", "mno", "pqrs", "tuv", "wxyz"};


void print_keypad(int num,string output)
{
    if (num == 0)
    {
        cout << output << endl;
        return;
    }

    int x = num % 10;
    int smallnumber = num / 10;
    string options = keys[x];

    for(int i=0;i<options.size();i++)
    {
        print_keypad(smallnumber,options[i]+output);
    }
    return;
}

int main()
{
    int n;
    cin >> n;

    print_keypad(n,"");
}