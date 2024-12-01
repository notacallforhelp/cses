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

bool cmp(pair<int,int> &a,pair<int,int> &b)
{
    return a.second<b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    int n, k; cin>>n>>k;
    vector<pair<int,int>> A(n);

    for(int i=0;i<n;i++)
    {
        cin>>A[i].first>>A[i].second;
    }
    sort(A.begin(),A.end(),cmp);

    set<pair<int,int>> s;

    ll bad=0;

    for(int i=0;i<n;i++)
    {
        if(s.size()==0)
        {
            s.insert({A[i].second*-1,i});
        }
        else
        {
            auto t = s.lower_bound({A[i].first*-1,-1});
            if(t!=s.end())
            {
                s.erase(t);
                s.insert({A[i].second*-1,i});
            }
            else
            {
                if(s.size()<k)
                {
                    s.insert({A[i].second*-1,i});
                }
                else
                {
                    ++bad;
                }
            }
        }
    }
    cout << n-bad << endl;
}