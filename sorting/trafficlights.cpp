#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);
    int x, n; cin>>x>>n;

    set<int> S;
    multiset<int> lengths;
    S.insert(0);
    S.insert(x);
    lengths.insert(x);

    for(int i=0;i<n;i++)
    {
        int light; cin>>light;
        S.insert(light);
        auto it = S.find(light);
        int prevval = *prev(it);
        int nextval = *next(it);
        lengths.erase(lengths.find(nextval-prevval));
        lengths.insert(light-prevval);
        lengths.insert(nextval-light);
        cout << *lengths.rbegin() << " ";
    }
}