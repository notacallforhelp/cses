#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

void solve()
{

    vector<pair<ll,ll>> A(3);

    for(int i=0;i<3;i++)
    {
        cin>> A[i].first >> A[i].second;
    }

    for(int i=1;i<3;i++)
    {
        A[i].first -= A[0].first;
        A[i].second -= A[0].second;
    }

    ll cp = A[2].first*A[1].second-A[2].second*A[1].first;
    if(cp<0)
    {
        cout << "LEFT\n";
    }
    else if(cp>0)
    {
        cout << "RIGHT\n";
    }
    else
    {
        cout << "TOUCH\n";
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}