#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

bool ans = false;
 
int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	
	//0 +
	//1 -
	for(int i=0;i<(1<<n);i++)//each i will represent a subset
	{
		int total = 0;
		
		for(int j=0;j<n;j++)
		{
			if((i&(1<<j))==0)//if that bit is not set
			{
				total+=a[j];
			}
			else
			{
				total-=a[j];
			}
		}
		
		if(total%360==0)
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
	
}