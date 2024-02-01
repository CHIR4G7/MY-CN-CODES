#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int printC(int index,vector<int> &ds,int s,int sum,int arr[],int n)
{
    //base case
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
            return 1;
        }
        return 0;
    }

    ds.push_back(arr[index]);
    s+=arr[index];

    int take = printC(index+1,ds,s,sum,arr,n);

    ds.pop_back();
    s-=arr[index];
    int not_take = printC(index+1,ds,s,sum,arr,n);

    return take + not_take;
     
}
 
int main()
{
    int arr[] = {1,2,1};
    int n = 3;
    int sum = 2;

    vector<int> ds;

    cout << printC(0,ds,0,sum,arr,n);
}