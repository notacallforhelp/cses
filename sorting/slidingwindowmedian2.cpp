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

    vector<int> A(n);

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    if(k==1)
    {
        for(int i=0;i<n;i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
        return 0;
    }

    if(k==2)
    {
        for(int i=1;i<n;i++)
        {
            cout << min(A[i-1],A[i])<<" ";
        }
        cout << endl;
        return 0;
    }

    vector<pair<int,int>> val;

    for(int i=0;i<k;i++)
    {
        val.push_back({A[i],i});
    }

    sort(val.begin(),val.end());

    set <pair<int,int>> leftSet;
    set <pair<int,int>> rightSet;

    for(int i=0;i<(k/2)+k%2;i++)
    {
        leftSet.insert(val[i]);
    }

    for(int i=(k/2)+k%2;i<k;i++)
    {
        rightSet.insert(val[i]);
    }

    cout << leftSet.rbegin()->first << " ";

    for(int i=1;i<n-k+1;i++)
    {
        if(leftSet.count({A[i-1],i-1}))
        {
            leftSet.erase({A[i-1],i-1});
        }
        else
        {
            rightSet.erase({A[i-1],i-1});
        }

        if(*(leftSet.rbegin())<make_pair(A[i+k-1],i+k-1))
        {
            rightSet.insert({A[i+k-1],i+k-1});
        }
        else
        {
            leftSet.insert({A[i+k-1],i+k-1});
        }

        while(leftSet.size()<k/2+(k%2))
        {
            pair<int,int> b = *(rightSet.begin());
            leftSet.insert(b);
            rightSet.erase(b);
        }

        while(leftSet.size()>k/2+(k%2))
        {
            pair<int,int> b = *(leftSet.rbegin());
            rightSet.insert(b);
            leftSet.erase(b);
        }

        cout << leftSet.rbegin()->first << " ";
    }
    cout << endl;

}