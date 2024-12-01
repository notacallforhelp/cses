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

    int n;
    cin>>n;

    int x; cin>>x;

    vector<pair<ll,int>> A(n);

    for(int i=0;i<n;i++)
    {
        cin>>A[i].first;
        A[i].second = i+1;
    }

    sort(A.begin(),A.end());

    for(int i=0;i<n;i++)
    {
        ll left = x-A[i].first;
        for(int j=i+1,k=n-1;j<n;j++)
        {
            while(A[k].first+A[j].first>left)
            {
                --k;
            }
            if(j<k&&A[k].first+A[j].first==left)
            {
                cout << A[i].second << " " << A[j].second << " " << A[k].second << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}