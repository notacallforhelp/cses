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

*/



const int m = 1e7;

const int mod = 1e9+7;
int dp[m];

int func(int i)
{
    if(dp[i]!=-1)
    {
        return dp[i]%mod;
    }
    if(i==0)
    {
        return 1;
    }
    ll output =0;
    for(int k=1;k<=6;k++)
    {
        if(i-k>=0)
        {
            output += func(i-k);
        }
    }

    return dp[i]=(output%mod);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    memset(dp,-1,sizeof(dp));

    int n; cin>>n;
    func(n);
    cout << dp[n] << endl;
}