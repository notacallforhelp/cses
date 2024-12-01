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

void solve()
{

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    int n; cin>>n;
    int x; cin>>x;

    vector<int> A(n+1);

    vector<int> pf(n+1);
    pf[0]=0;

    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
        pf[i]=pf[i-1]+A[i];
    }

    int l = 1;
    int r = 1;
    int count = 0;

    while(l<=n&&r<=n)
    {
        int sum = pf[r]-pf[l-1];
        if(sum<x)
        {
            ++r;
        }
        else if(sum>x)
        {
            ++l;
        }
        else
        {
            ++count;
            ++l;
            ++r;
        }
    }

    if(r==n+1&&l<=n)
    {
        int sum = pf[r-1]-pf[l-1];
        if(sum==x) ++count;
        ++l;

    }

    cout << count << endl;
}