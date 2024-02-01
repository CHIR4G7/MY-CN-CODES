#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>
using namespace std;

void seperate_words(string s,vector<string> &words)
{
    string word = "";
    for(auto i : s)
    {
        if(i == ' ')
        {
            words.push_back(word);
            word = "";
        }
        else
        {
            word = word + i;
        }
    }
    words.push_back(word);
}

bool wordPattern(string pattern,string s)
{
    vector<string> words;
    seperate_words(s,words);

    if(pattern.length()!=words.size())
    {
        return false;
    }
    unordered_map<char,string> map;
    set<string> st;//to keep a track of the words which are already in the map;
    for(int i=0;i<pattern.size();i++)
    {
        if(map.find(pattern[i])!=map.end())//present in map
        {
            if(map[pattern[i]]!=words[i])//present nd not matching with the mapped element hance return false;
            {
                return false;
            }
        }
        else
        {
            if(st.count(words[i])>0)//the word has occured more than once which is not possible a there should be one to one mapping.
            {
                return false;
            }
            map[pattern[i]] = words[i];
            st.insert(words[i]);
        }

    }
    return true;

}

int main()
{
    string pattern;
    getline(cin, pattern);

    string s;
    getline(cin, s);

    // cout << wordPattern(pattern, s) << endl;
    cout << wordPattern(pattern,s);
   
}