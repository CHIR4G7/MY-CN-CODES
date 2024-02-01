#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

//directions in which the rat can go;
int dirx[4] = {-1,1,0,0};
int diry[4] = {0,0,-1,1};

vector<string> findPath(vector<vector<int> > &maze,int n)
{
    
}
 
int main()
{
    int n;
    cin >> n;

    vector<vector<int> > maze(n,vector<int>(n));//the maze
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int u;
            cin >> u;
            maze[i][j] = u;
        }
    }

    vector<string> Paths;
    Paths = findPath(maze,n);
}