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


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    int n; cin>>n;
    vector<range> ranges(n);
    vector<ll> contained(n);
    vector<ll> contains(n);
    ordered_set<pair<ll,ll>> rightBoundaries;

    for(int i=0;i<n;i++)
    {
        cin>>ranges[i].l>>ranges[i].r;
        ranges[i].index=i;
    }

    sort(ranges.begin(),ranges.end());

    for(int i=0;i<n;i++)
    {
        rightBoundaries.insert({ranges[i].r,-1*i});
        contained[ranges[i].index]=
            rightBoundaries.size()-rightBoundaries.order_of_key({ranges[i].r,-1*i})-1;
    }
    rightBoundaries.clear();

    for(int i=n-1;i>=0;i--)
    {
        rightBoundaries.insert({ranges[i].r,-1*i});
        contains[ranges[i].index]=rightBoundaries.order_of_key({ranges[i].r,-1*i});
    }
    for(auto ele:contains)
    {
        cout << ele << " ";
    }

    cout << endl;

    for(auto ele:contained)
    {
        cout << ele << " ";
    }

    cout << endl;
}