#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;

    // SLIDING WINDOW
    int si = 0;
    int ei = 0;
    queue<int> neg; // CUZ WE NEED FIRST IN FIRST OUT

    while (ei < n)
    {
        if (arr[ei] < 0)
        {
            neg.push(arr[ei]);
        }

        if ((ei - si + 1) < k)
        {
            ei++;
        }
        else if ((ei - si + 1) == k)
        {
            if(neg.size()==0)
            {
                cout << "0" << " ";
                si++;
                ei++;
            }
            else
            {
                cout << neg.front() << " ";
                if(arr[si]==neg.front())
                {
                    neg.pop();
                    si++;
                    ei++;
                }
                else
                {
                    si++;
                    ei++;
                }
            }
        }
    }
}