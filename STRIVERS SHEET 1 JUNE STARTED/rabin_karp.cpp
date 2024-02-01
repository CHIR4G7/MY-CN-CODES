#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

#define d 256

vector<int> Rabin_karp(string txt,string pat)
{
    int m = pat.size();
    int n = txt.size();
    int hash_pat = 0;
    int hash_txt = 0;
    int q = 37;
    int h = 1;
    int i,j;
    vector<int> idx;

    //calculate the value of hash
    for(i=0;i<m-1;i++)
    {
        h = (h*d)%q;
    }

    //creating initial windows and thier hashe
    for(i=0;i<m;i++)
    {
        hash_pat = (hash_pat * d + pat[i]) % q;
        hash_txt = (hash_txt * d + txt[i]) % q;
    }

    //traversing windows;
    for(i=0;i<(n-m);i++)
    {
        if(hash_txt==hash_pat)
        {
            for(j=0;j<m;j++)
            {
                if(txt[i+j]!=pat[j])
                {
                    break;
                }
            }
            if(j==m)
            {
                idx.push_back(i);
            }
        }

        if(i<n-m)
        {
            hash_txt = ( (hash_txt-(h*txt[i]))*d + txt[i+m] ) % q;
            if(hash_txt<0)
            {
                hash_txt = hash_txt + q;
            }
        }

    }
    return idx;
}

 
int main()
{
    string txt,pat;
    cin >> txt >> pat;

    vector<int> indices = Rabin_karp(txt,pat);
    for(int i=0;i<indices.size();i++)
    {
        cout << indices[i] << " ";
    }
}