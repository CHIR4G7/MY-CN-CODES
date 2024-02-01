#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "hashmap_implementation.h"
using namespace std;
 
int main()
{
    ourMap<int> map;
    for(int i=0;i<10;i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key+c;
        int value = i+1;
        map.insert(key,value);
    }
    cout << map.getSize() << endl;
    cout << map.getLoadFactor()<< endl;
}