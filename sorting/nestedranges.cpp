#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

//ordered_sets
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

typedef long long int ll;
typedef long double ld;

bool cmp(pair<pair<int,int>,int> &a,pair<pair<int,int>,int> &b)
{
    if(a.first.first==b.first.first) return a.first.second>b.first.second;

    return a.first.first<b.first.first;
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    int n; cin>>n;

    vector<pair<pair<int,int>,int>> A(n);

    for(int i=0;i<n;i++)
    {
        int x, y; cin>>x>>y;
        A[i]={{x,y},i};
    }
    sort(A.begin(),A.end(),cmp);
    
    vector<bool> output(n);
    vector<bool> output2(n);

    int maxright = 0;

    for(int i=0;i<n;i++)
    {
        if(A[i].first.second<=maxright)
        {
            output[A[i].second]=true;
        }

        maxright = max(maxright,A[i].first.second);
    }

    int minright = 1e9+10;

    for(int i=n-1;i>=0;i--)
    {
        if(A[i].first.second>=minright)
        {
            output2[A[i].second]=true;
        }
        minright = min(minright,A[i].first.second);
    }
    for(auto ele:output2)
    {
        cout << ele << " ";
    }

    cout << endl;

    for(auto ele:output)
    {
        cout << ele << " ";
    }

    cout << endl;
}