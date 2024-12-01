#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


typedef long long int ll;
typedef long double ld;

//ordered_sets
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

//struct for range 
struct range
{
    ll l,r,index;
    bool operator < (const range &other) const
    {
        if(l==other.l)
            return r>other.r;
        return l < other.l;
    }
};

/*binary search template

while(hi-low>0)
    {
        ll mid = (low+hi)/2;
        ll products = 0;
        for(int i=0;i<n;i++)
        {
            products += min(mid/A[i],(ll)1e9);
        }
        if(products>=k)
        {
            if(mid<answer)
            {
                answer = mid;
            }
            hi = mid;
        }
        else
        {
            low = mid+1;
        }
    }


FOR SIMULATING ALL CELLS THAT SHARE A WALL WITH CURRENT CELL, GRID IS OF SIZE N*M*/

int dx[]={-1,0};
int dy[]={0,-1};

inline bool in(int i,int j,int n){
    return (0<=i&&i<n&&0<=j&&j<n);
}

const int mod = 1e9+7;


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    int n; cin>>n;

    vector<string> grid(n);
    for(int i=0;i<n;i++)
    {
        cin>>grid[i];
    }
    vector<vector<ll>> numberofpaths(n,vector<ll>(n,0));
    numberofpaths[0][0]=(grid[0][0]=='.');
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]!='*')
            {
                for(int k=0;k<2;k++)
                {
                    int xcord = i+dx[k];
                    int ycord = j+dy[k];
                    if(in(xcord,ycord,n)&&grid[xcord][ycord]!='*')
                    {
                        numberofpaths[i][j] += numberofpaths[xcord][ycord]%mod;
                    }
                }
            }
        }
    }
    cout << numberofpaths[n-1][n-1]%mod << endl;
}