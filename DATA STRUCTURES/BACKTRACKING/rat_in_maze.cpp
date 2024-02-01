#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

void printsolution(int **solution, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}

void mazehelp(int maze[][20],int n, int **solution,int x,int y)
{
    if(x==n-1 && y==n-1)
    {
        solution[x][y]=1;
        printsolution(solution,n);
        solution[x][y]=0;
        return;
    }
    if(x>=n || x<0 || y>=n || y<0 || maze[x][y]==0 || solution[x][y]==1)
    {
        return;
    }
    solution[x][y] = 1;
    mazehelp(maze,n,solution,x-1,y);//up
    mazehelp(maze,n,solution,x+1,y);//down
    mazehelp(maze,n,solution,x,y-1);//left
    mazehelp(maze,n,solution,x,y+1);//right
    solution[x][y] = 0;
}

void ratInMaze(int maze[][20], int n)
{
    //creating a solution array. 
    int **solution = new int *[n];

    for (int i = 0; i < n; i++)
    {
        solution[i] = new int[n];
    }
    for(int i=0;i<n;i++)
    {
        memset(solution[i],0,n * sizeof(int));
    }
    mazehelp(maze,n,solution,0,0);

}

int main()
{
    int n;
    cin >> n;

    int maze[20][20] = {0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;i++)
        {
            cin >> maze[i][j];
        }
    }
     ratInMaze(maze,n);
     return 0;
}