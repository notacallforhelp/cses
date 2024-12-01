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

    vector<pair<pair<int,int>,int>> customers(n);

    for(int i=0;i<n;i++)
    {
        cin>>customers[i].first.first>>customers[i].first.second;
        customers[i].second = i;
    }
    sort(customers.begin(),customers.end());

    vector<int> roomAssigned(n,-1);
    int roomId = 1;
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> rooms;

    for(int i=0;i<n;i++)
    {
        if(rooms.size()==0)
        {
            roomAssigned[customers[i].second] = roomId++;
            rooms.push(make_pair(customers[i].first.second,roomId-1));
        }
        else
        {
            if(rooms.top().first<customers[i].first.first)
            {
                roomAssigned[customers[i].second]= rooms.top().second;
                pair<int,int> x=rooms.top();
                rooms.pop();
                rooms.push(make_pair(customers[i].first.second,x.second));
            }
            else
            {
                roomAssigned[customers[i].second] = roomId++;
                rooms.push(make_pair(customers[i].first.second,roomId-1));
            }
        }
    }
    cout << roomId-1 << endl;
    for(int i=0;i<n;i++)
    {
        cout << roomAssigned[i] << " ";
    }

    cout << endl;
}
