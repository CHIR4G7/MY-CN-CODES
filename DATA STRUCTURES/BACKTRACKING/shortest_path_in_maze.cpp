#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

bool isSafe(vector<vector<int> > &mat,vector<vector<bool> > &visited,int x,int y)
{
    int n = mat.size();
    int m = mat[0].size();

    if(x>=0 && x<n && y>=0 && y<m && mat[x][y]==1 && visited[x][y]==false)
    {
        return true;
    }
    return false;
}


void findShortestPath(vector<vector<int>> &mat,vector<vector<bool> > &visited,int i,int j,int x,int y,int &mind,int dist)
{
    if(i==x && j==y)
    {
        mind = min(mind,dist);
        return;
    }

    visited[i][j] = true;

//down
    if(isSafe(mat,visited,i+1,j))
    {
        findShortestPath(mat,visited,i+1,j,x,y,mind,dist+1);
    }

    //up
     if(isSafe(mat,visited,i-1,j))
    {
        findShortestPath(mat,visited,i-1,j,x,y,mind,dist+1);
    }

    //left
     if(isSafe(mat,visited,i,j-1))
    {
        findShortestPath(mat,visited,i,j-1,x,y,mind,dist+1);
    }

    //right
     if(isSafe(mat,visited,i,j+1))
    {
        findShortestPath(mat,visited,i,j+1,x,y,mind,dist+1);
    }

    visited[i][j] = false;

}

int findShortestPathLength(vector<vector<int>> &mat,pair<int,int> &src,pair<int,int> &dest)
{
    if(mat.size()==0 || mat[src.first][src.second]==0 || mat[dest.first][dest.second]==0)
    {
        return -1;
    }

    int n = mat.size();
    int m = mat[0].size();

    vector<vector<bool> > visited(n,vector<bool>(m,false));

    int dist = INT_MAX;
    findShortestPath(mat,visited,src.first,src.second,dest.first,dest.second,dist,0);
    if(dist==INT_MAX)
    {
        return -1;
    }
    return dist;
}

int main()
{

    vector<vector<int>> mat =
        {{1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
         {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
         {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
         {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
         {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
         {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
         {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
         {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
         {1, 1, 0, 0, 0, 0, 1, 0, 0, 1}};

    pair<int,int> src = make_pair(0,0);
    pair<int,int> dest = make_pair(3,4);

    int dist = findShortestPathLength(mat,src,dest);
    if(dist!=-1)
    {
        cout << dist;
    }
}