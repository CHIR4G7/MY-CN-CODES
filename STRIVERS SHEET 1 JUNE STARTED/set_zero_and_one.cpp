#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int> > mat(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
   

//map me wo rows aur cols store kara ke rkh lo jisme saare elemnts zeros honge kyunki isi ke corresponding cell me zero milega.
    unordered_map<int, bool> rows;
    unordered_map<int, bool> cols;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
            {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }

     for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((rows.find(i)!=rows.end()) || (cols.find(j)!=cols.end()))//ab map me confirm krte jao ki jis row ya cell me tum pahunche vo zero hoga ya nhi.
                {
                    mat[i][j] = 0;
                }
            }
        }

}