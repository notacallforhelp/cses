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

    vector<int> values(n);

    for(int i=0;i<n;i++)
    {
        cin>>values[i];
    }

    if(k==1)
    {
        for(int i=0;i<n;i++)
        {
            cout << 0 << " ";
        }

        cout << endl;
        return 0;
    }

    if(k==2)
    {
        for(int i=1;i<n;i++)
        {
            cout << abs(values[i]-values[i-1]) << " ";
        }

        cout << endl;
        return 0;
    }

    vector<pair<int,int>> hmm;

    for(int i=0;i<k;i++)
    {
        hmm.push_back({values[i],i});
    }

    sort(hmm.begin(),hmm.end());

    set<pair<int,int>> leftSet;
    set<pair<int,int>> rightSet;

    ll leftSum=0;
    ll rightSum=0;

    for(int i=0;i< k/2+(k%2);i++)
    {
        leftSet.insert(hmm[i]);
        leftSum += hmm[i].first;
    }

    for(int i=k/2 +(k%2);i<k;i++)
    {
        rightSet.insert({hmm[i]});
        rightSum += hmm[i].first;
    }

    ll leftset_sz = leftSet.size();
    ll rightset_sz = rightSet.size();
    ll median = leftSet.rbegin()->first;

    //cout << leftSum<< " "<<rightSum << " "<< endl;

    cout << leftset_sz*median - leftSum + rightSum - rightset_sz*median<<" ";

    for(int i=1;i<n-k+1;i++)
    {
        if(leftSet.count({values[i-1],i-1}))
        {
            leftSum -= values[i-1];
            leftSet.erase({values[i-1],i-1});
        }
        else
        {
            rightSum -= values[i-1];
            rightSet.erase({values[i-1],i-1});
        }

        if(*leftSet.rbegin()<make_pair(values[i+k-1],i+k-1))
        {
            rightSum += values[i+k-1];
            rightSet.insert({values[i+k-1],i+k-1});
        }
        else
        {
            leftSum += values[i+k-1];
            leftSet.insert({values[i+k-1],i+k-1});
        }

        while(leftSet.size()< k/2 + (k%2))
        {
            pair<int,int> b = *rightSet.begin();
            leftSet.insert(b);
            leftSum += b.first;
            rightSet.erase(b);
            rightSum -= b.first;
        }

        while(leftSet.size()> k/2 + (k%2))
        {
            pair<int,int> b = *leftSet.rbegin();
            rightSet.insert(b);
            rightSum += b.first;
            leftSet.erase(b);
            leftSum -= b.first;
        }

        median = leftSet.rbegin()->first;

        cout << leftset_sz*median - leftSum + rightSum - rightset_sz*median<<" ";
    }

    cout << endl;
}