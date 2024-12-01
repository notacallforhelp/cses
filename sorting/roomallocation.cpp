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

bool cmp(pair<pair<ll,ll>,ll> &a,pair<pair<ll,ll>,ll> &b)
{
    if(a.first.first==b.first.first)
    {
        if(a.first.second!=b.first.second)
        {
            return a.first.second<b.first.second;
        }
        else
        {
            return a.second < b.second;
        }
    }
    return a.first.first<b.first.first;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    int n; cin>>n;

    map<ll,ll> entries;  
    map<ll,ll> exits;

    vector<pair<pair<ll,ll>,ll>> kustomers;

    vector<ll> answers(n);
    ordered_set<pair<ll,ll>> test;

    for(ll i=0;i<n;i++)
    {
        ll x, y; cin>>x>>y;
        ++entries[x];
        ++exits[y+1];

        kustomers.push_back({{x,y+1},i});
    }

    sort(kustomers.begin(),kustomers.end(),cmp);

    for(auto ele:kustomers)
    {
        cout << ele.first.first << " " << ele.first.second << " " << ele.second << endl;
    }

    for(int i=0;i<kustomers.size();i++)
    {
        while(!test.empty()&&(test.find({4,}))
        {
            test.erase(test.begin());
        }
        test.insert({kustomers[i].first.second,kustomers[i].second});
        answers[kustomers[i].second]=test.order_of_key({kustomers[i].first.second,kustomers[i].second})+1;
    }

    for(int i=0;i<n;i++)
    {
        cout << answers[i] << " ";
    }

    cout << endl;

    /*ll global = 0;
    ll local = 0;

    auto it = entries.begin();
    auto it2 = exits.begin();

    set<ll> free;
    for(ll i=1;i<=1e5;i++)
    {
        free.insert(i);
    }
    set<ll> occupied;
    vector<ll> output;

    while(it!=entries.end()&&it2!=exits.end())
    {
        if(it->first<it2->first)
        {
            local += it->second;

            for(int i=0;i<it->second;i++)
            {
                occupied.insert(*(free.begin()));
                output.push_back(*(free.begin()));
                free.erase(free.begin());
            }

            ++it;

        }
        else if(it->first>it2->first)
        {
            local -= it2->second;

            for(int i=0;i<it2->second;i++)
            {
                free.insert(*(occupied.begin()));
                occupied.erase(occupied.begin());
            }

            ++it2;
            
        }
        else
        {
            local += it->second;
            local -= it2->second;

            for(int i=0;i<it2->second;i++)
            {
                free.insert(*(occupied.begin()));
                occupied.erase(occupied.begin());
            }

            for(int i=0;i<it->second;i++)
            {
                occupied.insert(*(free.begin()));
                output.push_back(*(free.begin()));
                free.erase(free.begin());
            }

            ++it;
            ++it2;
        }
        global = max(global,local);
    }

    while(it2!=exits.end())
    {
        local -= it2->second;

        for(int i=0;i<it2->second;i++)
        {
            free.insert(*(occupied.begin()));
            occupied.erase(occupied.begin());
        }

        ++it2;
    }

    while(it!=entries.end())
    {
        local += it->second;

        for(int i=0;i<it->second;i++)
        {
            occupied.insert(*(free.begin()));
            output.push_back(*(free.begin()));
            free.erase(free.begin());
        }

        ++it;
    }

    global = max(global,local);

    cout << global << endl;

    for(auto ele:output)
    {
        cout << ele << " ";
    }

    cout << endl;*/
}