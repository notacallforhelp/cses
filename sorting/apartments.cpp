#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    ll n, m, k;

    cin>>n>>m>>k;

    vector<ll> wish(n);
    vector<ll> size(m);

    for(int i=0;i<n;i++)
    {
        cin>>wish[i];
    }

    for(int i=0;i<m;i++)
    {
        cin>>size[i];
    }

    sort(wish.begin(),wish.end());
    sort(size.begin(),size.end());

    int l= 0;
    int r = 0;
    int output = 0;

    while(l<n&&r<m)
    {
        if(abs(wish[l]-size[r])<=k)
        {
            ++output;
            ++l;
            ++r;
        }
        else if(wish[l]<size[r])
        {
            ++l;
        }
        else
        {
            ++r;
        }
    }
    cout << output << endl;
}