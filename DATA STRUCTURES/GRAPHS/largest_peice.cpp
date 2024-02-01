#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <queue>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int bfs(int n, vector<vector<int> > &cake, int x, int y, vector<vector<bool> > &visited)
{
    queue<pair<int, int> > pending;
    pending.push(make_pair(x,y));
    int count = 1;
    visited[x][y] = true;

    while (pending.size() != 0)
    {
        pair<int,int> front = pending.front();
        pending.pop();

        for(int k=0;k<4;k++)
        {
            int row = front.first + dx[k];
            int col = front.second + dy[k];
            if(row>=0 && row<n && col>=0 && col<n && visited[row][col]==false && cake[row][col]==1)
            {
                count++;
                visited[x][y] = true;
                pending.push(make_pair(x,y));
            }
        }
    }
    return count;
}

int getBiggestPeiceSize(vector<vector<int> > &cake, int n)
{
    vector<vector<bool> > visited(n, vector<bool>(n, false));
    int size = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cake[i][j] == 1 && visited[i][j] == false)
            {
                size = max(size, bfs(n, cake, i, j, visited));
            }
        }
    }
    return size;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int> > cake(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cake[i][j];
        }
    }
    cout << getBiggestPeiceSize(cake, n);
}