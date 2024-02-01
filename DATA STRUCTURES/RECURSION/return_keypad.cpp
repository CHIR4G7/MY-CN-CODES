#include <iostream>
#include <string>
using namespace std;

string keys[] = {" ", " ", "abc", "def", "ghi", "mno", "pqrs", "tuv", "wxyz"}; // is array me har keynumber ke corresponding alphabets hai

int keypad(int n, string output[])
{
    // base case;

    if (n == 0)
    {
        output[0] = " ";
        return 1;
    }

    int smallnumber = n / 10;
    int lastdigit = n % 10;

    int smalloutputsize = keypad(smallnumber,output);
    string options = keys[lastdigit];

    for(int i=0;i<options.length()-1;i++)
    {
        for(int j=0;j<smalloutputsize;j++)
        {
            output[(i+1)*smalloutputsize + j] = output[j];
        }

    }

    int k=0;
    for(int i=0;i<options.length();i++)
    {
        for(int j=0;j<smalloutputsize;j++)
        {
            output[k] = output[k] + options[i];
            
        }
    }
    return smalloutputsize * options.length();

}

int main()
{
    int n;
    cin >> n;

    string output[10000];
    int count = keypad(n, output);
    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }
}