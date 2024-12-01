#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    int n, k; cin>>n>>k;

    ordered_set<int> children;

    for(int i=1;i<=n;i++)
    {
        children.insert(i);
    }
    int startPosition = 0;

    while(children.size()>0)
    {
        startPosition %= children.size();
        int positiontoremove = (startPosition+k)%children.size();

        auto it = children.find_by_order(positiontoremove);
        cout << *it << " ";
        children.erase(it);
        startPosition = positiontoremove;
    }

    //cout << *children.begin() << endl;
}