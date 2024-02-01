#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include "trie_class.h"
using namespace std;
 
int main()
{
   Trie t;
   
   int n;
   cin >> n;
   vector<string> vect;
   for(int i=0;i<n;i++)
   {
    string s;
    cin >> s;
    vect.push_back(s);
   }

   for(int i=0;i<vect.size();i++)
   {
    string word = vect[i];
    for(int j=0;j<word.length();j++)
    {
        t.insert(word.substr(j));
    }
   }
   string s;
   cin >> s;
   cout << t.search(s);
}