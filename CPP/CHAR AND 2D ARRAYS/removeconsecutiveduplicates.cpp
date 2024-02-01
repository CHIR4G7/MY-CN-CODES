#include <iostream>
using namespace std;

void removeConsecutiveDuplicates(char input[]) {
    // Write your code here
     int len = strlen(input);

    int j = 1;
    int count = 1;
    for (int i = 1; i < len+1; i++)
    {
        if (input[i] != input[i - 1])
        {
            input[j] = input[i];
            j++;
            count++;
        }
    }
}

int main()
{
    int size = 1e6;
    char str[size];
    cin >> str;
    removeConsecutiveDuplicates(str);
    cout << str;
}