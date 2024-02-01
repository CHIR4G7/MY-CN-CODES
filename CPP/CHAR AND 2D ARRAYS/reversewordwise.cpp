#include <iostream>
using namespace std;

int len(char input[])
{
    int count = 0;
    for(int i = 0;input[i]!='\0';i++)
    {
        count++;
        
    }
    return count;
}

void reverse_string(char input[], int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = input[start];
        input[start] = input[end];
        input[end] = temp;
        start++;
        end--;
    }
}

void reverseStringWordWise(char input[]) {
    // Write your code here
    int i = 0, j = 0;
    reverse_string(input, 0, len(input) - 1);

    while (input[i] != '\0')
    {
        while (input[j] != 32 && input[j] != '\0')
        {
            j++;
        }
        reverse_string(input, i, j - 1);
        i = ++j;
    }
}
 
int main()
{
     char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
