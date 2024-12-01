#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int n; cin>>n;
    vector<ll> A(n);

    for(int i=0;i<n;i++) cin>>A[i];

    sort(A.begin(),A.end());

    ll sum=0;

    for(int i=0;i<n;i++)
    {
        if(A[i]>sum+1)
        {
            cout<<sum+1 << endl;
            return 0;
        }
        sum+=A[i];
    }

    cout << sum+1<<endl;


}