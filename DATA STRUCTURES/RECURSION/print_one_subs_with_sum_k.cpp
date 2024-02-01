#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

bool printOne(int index,vector<int> &ds,int s,int sum,int arr[],int n)
{
    if(index==n)
    {
        //condition satisfied
        if(s==sum)
        {
            for(auto i : ds)
            {
                cout << i << " ";
            }
            cout << endl;
            return true;
        }

        //condiiton not satisified
        return false;
    }

//take
    ds.push_back(arr[index]);
    s+=arr[index];

//if u get ans then just return no further recursive calls required.
    if(printOne(index+1,ds,s,sum,arr,n)==true)
    {
        return true;
    }

//not take
    ds.pop_back();
    s-=arr[index];


    if(printOne(index+1,ds,s,sum,arr,n)==true)
    {
        return true;
    }

    return false;
}
 
int main()
{
    int arr[] = {1,2,1};
    int n = 3;
    int sum = 2;

    vector<int> ds;
    cout << printOne(0,ds,0,sum,arr,n);
}