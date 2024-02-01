#include <iostream>
using namespace std;

// bool isPermutation(char input1[], char input2[]) {
//     // Write your code here
//     int len1 = strlen(input1);
//     //int len2 = strlen(input2);
//     int count = 0;

//     //if(len1 != len2)
//     //{
//         //return false;

//     //}

//         for(int i  =0;i<len1;i++)
//         {
//             for(int j = 0;j<len1;j++)
//             {
//                 if(input1[i] == input2[j])
//                 {
//                     input2[j] = '?';
//                     count++;

//                     //continue;
//                     break;

//                 }
//             }
//         }

//     if(count==len1)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

bool isPermutation(char input1[], char input2[])
{
    int temp[256];

    for (int x = 0; x < 256; x++)
    {
        temp[x] = 0;
    }
    int flag = 0;
    for (int i = 0; i < strlen(input1); i++)
    {
        int a = input1[i];
        temp[a]++;
    }
    for (int j = 0; j < strlen(input2); j++)
    {
        int b = input2[j];
        temp[b]--;
    }
    for (int k = 0; k < 256; k++)
    {
        if (temp[k] == 0)
        {
            flag = 0;
        }
        else
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
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
    char str1[size];
    char str2[size];
    cin >> str1 >> str2;
    cout << (isPermutation(str1, str2) ? "true" : "false");
}