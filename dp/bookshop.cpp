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

FOR SIMULATING ALL CELLS THAT SHARE A WALL WITH CURRENT CELL, GRID IS OF SIZE N*M

int dx[]={-1,0,+1,0};
int dy[]={0,-1,0,+1};

inline bool in(int i,int j){
    return (0<=i&&i<n&&0<=j&&j<m);
}

*/


void solve()
{
    int n, x; cin>>n>>x;
    vector<int> prices(n);
    vector<int> pages(n);
    for(int i=0;i<n;i++)
    {
        cin>>prices[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>pages[i];
    }
    vector<vector<int>> maxPages(n+1,vector<int>(x+1,0));
    for(int i=0;i<n;i++)
    {
        for(int price=0;price<=x;price++)
        {
            maxPages[i+1][price]=maxPages[i][price];
            if(price>=prices[i])
            {
                maxPages[i+1][price] = max(maxPages[i+1][price],pages[i]+maxPages[i][price-prices[i]]);
            }
        }
    }
    cout << maxPages[n][x]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    int t=1;

    while(t--)
    {
        solve();
    }
}