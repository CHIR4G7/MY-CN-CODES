#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

void printS(int index,vector<int> &ds,int s,int sum,int arr[],int n)
{
    //the base case
    if(index==n)
    {
        if(s==sum)
        {
            //print the data structure
            for(auto i : ds)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        return;
    }

    //add
    ds.push_back(arr[index]);
    s+=arr[index];
    printS(index+1,ds,s,sum,arr,n);

    //remove;
    s-=arr[index];
    ds.pop_back();
    printS(index+1,ds,s,sum,arr,n);
}
 
int main()
{
    int arr[] = {1,2,1};
    int n = 3;
    int sum = 2;
    
    //the data structure
    vector<int> ds;
    printS(0,ds,0,sum,arr,n);
}