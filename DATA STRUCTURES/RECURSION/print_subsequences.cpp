#include <iostream>
using namespace std;

void helper(int index,string input,string &output)
{
    if(index>=input.length())
    {
        cout << output << endl;
        return;
    }

    //include
    output+=input[index];
    helper(index+1,input,output);
    output = output.substr(0,output.size()-1);

    //exclusion
    helper(index+1,input,output);

}

void print_subsequences(string input, string &output)
{
   return helper(0,input,output);
}



int main()
{
    string s;
    cin >> s;

    string output = "";
    print_subsequences(s,output);
}