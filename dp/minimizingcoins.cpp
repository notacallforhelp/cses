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
const int m = 1e6+10;
vector<ll> dp(m,-1);

ll func(ll x,vector<ll> &A)
{
    if(dp[x]!=-1)
    {
        return dp[x];
    }
    if(x==0)
    {
        return 0;
    }
    ll output = 1e10;
    for(int i=0;i<A.size();i++)
    {
        if(x-A[i]>=0)
        {
            output = min(output,1+func(x-A[i],A));
        }
    }
    return dp[x]=output;
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    ll n, x; cin>>n>>x;

    vector<ll> A(n);

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    ll answer = func(x,A);
    if(answer==1e10)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << answer << endl;
    }
    //cout << func(x,A) << endl;
}