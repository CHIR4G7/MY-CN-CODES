#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

bool isPrime(int n)
{
    if(n==0 || n==1)
    {
        return false;
    }
    for(int i=2;i<=(n/2);i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

vector<int> primes(int n)
{
    vector<int> v;
    for(int i=2;i<n;i++)
    {
        if(isPrime(i))
        {
            v.push_back(i);
        }
    }
    return v;
}
 
int main()
{
    int n;
    cin >> n;

    vector<int> nums;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    
    for(int i=0;i<n;i++)
    {
        int k = nums[i] - (i+1);
        
    }

}