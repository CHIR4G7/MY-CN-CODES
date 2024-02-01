#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;
 
int main()
{
    string s;
    cin >> s;

    unordered_set<char> map;
    unordered_set<char> se;
    se.insert('h');
    se.insert('e');
    se.insert('l');
    se.insert('o');

    queue<char> order;

    for(int i=0;i<s.length();i++)
    {
        if(se.find(s[i])!=se.end() && map.find(s[i])==map.end())//se me to hai but map me nhi hai
        {
            map.insert(s[i]);
            order.push(s[i]);
        }
    }
    string h = "hello";
    string m = "";
    while(order.size()!=0)
    {
        char front = order.front();
        order.pop();
        m+=front;
    }
    cout << m;
}