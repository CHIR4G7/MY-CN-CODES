#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int count0(string s)
{
    int c= 0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0')
        {
            c++;
        }
    }
    return c;
}
int count1(string s)
{
    int c = 0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1')
        {
            c++;
        }
    }
    return c;
}

int minflips(string s)
{
    int c_0=0;
        int c_1=0;
        // int c_1_b = 0;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
            {
                c_0 = count0(s.substr(i+1));
                break;
            }
        }

        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='0')
            {
                c_1 = count1(s.substr(i+1));
                break;
            }
        }

        reverse(s.begin(),s.end());
        int c_0_b = 0;
        int c_1_b = 0;

        for(int i =0;i<s.length();i++)
        {
            if(s[i]=='1')
            {
                c_0_b = count0(s.substr(i+1));
                break;
            }
        }
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='0')
            {
                c_1_b = count1(s.substr(i+1));
                break;
            }
        }

        cout << c_0 << " " << c_1 << " " << c_0_b << " " << c_1_b << endl;

        return min(min(c_0,c_1),min(c_0_b,c_1_b));
}
 
int main()
{
    string s;
    cin >> s;

    int c_0 = 0;//no. of 0's after first 1 is found
    int c_1=0;//no. of 1's after first 0 is found

    // for(int i=0;i<s.length();i++)
    // {
    //     if(s[i]=='1')
    //     {
    //        c_0 = count0(s.substr(i+1));
    //        break;
    //     }
    // }
    // cout << c_0 << endl;

    // for(int i=0;i<s.length();i++)
    // {
    //     if(s[i]=='0')
    //     {
    //         c_1 = count1(s.substr(i+1));
    //         break;
    //     }
    // }
    // cout << c_1 << endl;

    // cout << min(c_0,c_1);
    cout << minflips(s);
    
}