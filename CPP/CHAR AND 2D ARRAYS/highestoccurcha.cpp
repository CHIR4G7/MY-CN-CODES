#include <iostream>
using namespace std;

char highestOccurringChar(char input[]) 
{
    // Write your code here
    int len = strlen(input);
    
    int frequency[256] = {0};
    int max = 0;
    int max_i;
    for (int i = 0; i < len; i++)
    {
        int ascii = input[i];
        frequency[ascii+1]++;
    }

    for (int i = 0; i < 256; i++)
    {
        if (frequency[i] > max)
        {
            max = frequency[i];
            max_i = i;
        }
    }
    //
    char max_c = max_i-1;

    return max_c;
}
 
int main()
{
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << highestOccurringChar(str);

}