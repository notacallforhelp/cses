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

    int n, k; cin>>n>>k;

    vector<ll> A(n);

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    map<int,int> M;

    int i=0;
    int j=0;

    ll cnt = 0;

    while(i<n&&j<n)
    {
        if(M.size()<k||M.count(A[j])>0)
        {
            ++M[A[j]];
            ++j;
        }
        else
        {
            cnt += j-i;
            --M[A[i]];
            if(M[A[i]]==0)
            {
                M.erase(A[i]);
            }
            ++i;
        }
    }

    while(j==n&&i<n)
    {
        cnt += j-i;
        --M[A[i]];
        if(M[A[i]]==0)
        {
            M.erase(A[i]);
        }
        ++i;
    }

    cout << cnt << endl;

}