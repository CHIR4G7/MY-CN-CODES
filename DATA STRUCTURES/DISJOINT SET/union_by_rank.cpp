#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

class DisjointSet
{
    private :
    vector<int> rank;
    vector<int> parent;
    vector<int> size;

    public :

    DisjointSet(int n)
    {
        size.resize(n+1,1);
        rank.resize(n+1,0);//1 base indexing graph (defining it with n+1 will work with 0 and 1 based indexing both)
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i] = i;
        }
    }

    int findUltPar(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node] = findUltPar(parent[node]);//path compression by storing also and returning also
    }

    void UnionByRank(int u,int v)
    {
        int ulp_u = findUltPar(u);
        int ulp_v = findUltPar(v);

        if(ulp_u==ulp_v)
        {
            return;
        }
        if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else//i can do anything i.e. attach anyone anywhere
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;//u pe attach kiya to uska rank badhgya
        }
    }

    void UnionBySize(int u,int v)
    {
        int ulp_u = findUltPar(u);
        int ulp_v = findUltPar(v);

        if(ulp_u==ulp_v)
        {
            return;
        }

        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else 
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
 
int main()
{
    DisjointSet ds(7);
    ds.UnionByRank(1,2);
    ds.UnionByRank(2,3);
    ds.UnionByRank(4,5);
    ds.UnionByRank(6,7);
    ds.UnionByRank(5,6);

    if(ds.findUltPar(3) == ds.findUltPar(7))
    {
        cout << "same" << endl;
    }
    else
    {
        cout << "not same" << endl;
    }

    ds.UnionByRank(3,7);

     if(ds.findUltPar(3) == ds.findUltPar(7))
    {
        cout << "same" << endl;
    }
    else
    {
        cout << "not same" << endl;
    }
}
