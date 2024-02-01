#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map> //included map
using namespace std;

int main()
{
    unordered_map<string, int> ourMap;//<key type, value type>

    //insert Method-1
    pair<string,int> p("abc",1);
    ourMap.insert(p);

    //insert Method-2
    ourMap["def"] = 2;

    //find or access elements
    cout << ourMap["abc"] << endl; 
    cout << ourMap.at("abc") << endl;
    //cout << ourMap.at("ghi") << endl;//will give not found as key does not exist.
    cout << ourMap["ghi"] << endl; //here is the diffence between .at function and [ ] brackets, that at function gives error if key does not exist, whereas the square bracket does inserts that key if not present and assigns it a value 0 and then returns it.
    cout << ourMap.at("ghi") << endl;

    //check presence
    if(ourMap.count("ghi") > 0)
    {
        cout << "ghi is present" << endl;
    }

    //size of the map
    cout << "size : " << ourMap.size() << endl;

    //erase
    ourMap.erase("ghi");
     if(ourMap.count("ghi") > 0)
    {
        cout << "ghi is present" << endl;
    }
}
