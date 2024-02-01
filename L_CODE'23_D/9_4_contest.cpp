#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <queue>
using namespace std;

int minVisitedCells(vector<vector<int> > &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool> > visited(m,vector<bool>(n,false));
    queue<pair<int,int> > pending;
    pending.push({0,0});
    int ans = 0;
    while(pending.size()!=0)
    {
        int size = pending.size();
        while(size!=0)
        {
            pair<int,int> front = pending.front();
            pending.pop();
            int x = front.first;
            int y = front.second;
            if(x==n-1 && y==m-1)
            {
                return ans;
            }
            int val = grid[x][y];
            for(int it = min(n-1,x);it>=x+1;it--)
            {
                if(visited[it][y]==false)
                {
                    visited[it][y] = true;
                    pending.push({it,y});
                }
            }
            for(int it = min(m-1,y);it>=y+1;it--)
            {
                if(visited[x][it]==false)
                {
                    visited[x][it] = true;
                    pending.push({x,it});
                }
            }

            size--;
        }
    }
    return -1;
    
}
 
int main()
{
    int m,n;
    cin >> m >> n;

    vector<vector<int> > grid(m,vector<int>(n,0));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int a;
            cin >> a;
            grid[i][j] = a;
        }
    }

    cout << minVisitedCells(grid);
}