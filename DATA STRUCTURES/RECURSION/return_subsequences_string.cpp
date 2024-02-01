#include <iostream>
using namespace std;

int subsequences(string &input, string output[])
{
    //empty string ka ek hi subsequqnce hota.
    if (input.size() == 0)
    {
        output[0] = " ";
        return 1;
    }

    // getting a substring without the first character;
    string smallstring = input.substr(1);

    //ek index chod ke jo string ayi small usko pass krdiya ..
    int smalloutputsize = subsequences(smallstring, output);//isme hamne maana ki baaki string ke substrs aa chuke hai hame bas first char attach krna hai
    
    //and uske liye loop chalayi jo pehle se bane hue substrings hai unko to as it iz rkah ke ..fir unko copy kiya aur un copis ke aage pehla character attach krke fir output me store kiya

    for(int i=0;i<smalloutputsize;i++)
    {
        //smalloputputsize index tk to mere pass pehle wale pde uske aage mai copy krke daalunga
        output[i+smalloutputsize]  = input[0] + output[i];
    }
    return 2 * smalloutputsize;//jitni size hoga unko aur unke aage char laga ke to vo double hi hoajeyga na
}

int main()
{
    string input;
    cin >> input;

    string *output = new string[10000];
    int count = subsequences(input, output);
    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }
    cout << count << endl;
}