#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

vector<int> solve(int A,vector<int> &B)
{
    
    //first we will find the minimum element from the array of positive strengh.
    int mini = *min_element(B.begin(),B.end());

    //now we will find the maximum number of elements which ca be include, as WE CAN USE THE PERSON OF A PARTICULAR STRGNTH UNLIMITED TIMES, SO IF WE USE THE PERSON WITH MINIMUM STRENGTH ONLY THEN WE CA KICK MAXIMUM TIMES.
    int n = (A/mini);

    //now we will create a vector of size n
    vector<int> result(n);


    //now for keeping a track of index on the B vector, and no. of elements include we will use tw pointer
    int idx = 0;
    int taken = 0;

    while(idx<B.size())
    {
        if(A<B[idx])//if the resistance left in tushar is not sufficeint for the power show by the person at that index, then shift to next index person
        {
            idx++;
        }
        else if(taken+1+(A-B[idx]/mini)<n)
        {
            idx++;
        }
        else
        {
            result[taken] = idx;
            taken++;
            A-=B[idx];
            if(taken==n)
            {
                break;
            }
        }
    }
    return result;
}
 
int main()
{
    int n;
    cin >> n;

    vector<int> B(n);//the positive strength array.
    for(int i=0;i<n;i++)
    {
        cin >> B[i];
    }

    int A;//the maximum resistance, THE MAXIMUM SUM OF ELEMENTS THAT CAN BE INLCUDED WITH KEEPING THE NUMBER OF ELEMENTS MAXIMUM.
    cin >> A;

    vector<int> ans = solve(A,B);
    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i] << " ";
    }
}