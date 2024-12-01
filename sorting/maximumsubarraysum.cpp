#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int n;
    cin>>n;

    vector<ll> A(n);

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    ll local = A[0];
    ll global = A[0];

    for(int i=1;i<n;i++)
    {
        local = max(A[i],local+A[i]);
        global = max(local,global);
    }

    cout << global << endl;
}