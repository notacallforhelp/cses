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


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    int n,a,b; cin>>n>>a>>b;

    vector<ll> A(n+1);
    vector<ll> pf(n+1);
    pf[0]=0;

    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
        pf[i]=pf[i-1]+A[i];
    }

    ll sum = LLONG_MIN;
    ll global = LLONG_MIN;

    set<pair<ll,int>> S;

    for(int i=a;i<=b;i++)
    {
        S.insert({pf[i],i});
    }
    sum = S.rbegin()->first-pf[0];
    //cout << sum << endl;
    global = max(global,sum);

    for(int i=1;i<=n-a+1;i++)
    {
        sum = S.rbegin()->first-pf[i-1];
        global = max(sum,global);
        S.erase({pf[i+a-1],i+a-1});
        if(i+b<=n)
        {
            S.insert({pf[i+b],i+b});
        }
    }

    cout << global << endl;
}