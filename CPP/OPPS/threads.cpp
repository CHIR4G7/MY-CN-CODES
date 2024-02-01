#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <thread>
using namespace std;

void f(int z)
{
    cout << z << " ";
}
 
int main()
{
    std::thread t1(f,3);
    // cout << "h";
}