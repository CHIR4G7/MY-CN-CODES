#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    unordered_map<string, int> map;
    map["abc"] = 1;
    map["abc1"] = 1;
    map["abc2"] = 1;
    map["abc3"] = 1;
    map["abc4"] = 1;
    map["abc5"] = 1;

    unordered_map<string, int>::iterator it;
    it = map.begin(); // beginning point

    while (it != map.end())
    {
        cout << "key : " << it->first << " "
             << "value : " << it->second << endl;
        it++;
    }

    //find 
    unordered_map<string,int>::iterator it_find =  map.find("abc");//will give you an iterator
    
    //erase function ko bhi iterator pass kr skte hain
   
   //would make sense in vector.
   //f map.erase(it,it+4);//passing the (start,end). will go upto end-1.


cout << endl;
    // iterator over vectors
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    vector<int>::iterator it_v;
    it_v = v.begin();

    while (it_v != v.end())
    {
        cout << *it_v << endl;
        it_v++;
    }
}