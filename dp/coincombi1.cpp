#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

typedef long long int ll;

int func(int i,vector<int> &A,vector<ll> &dp,int n)
{
    
    if(i==0)
    {
        return 1;
    }
    if(i<0)
    {
        return 0;
    }
    if (dp[i]!=-1)
    {
        return dp[i];
    }
    ll output = 0;
    for(int j=0;j<n;j++)
    {
        output += func(i-A[j],A,dp,n)%mod;
    }
    return dp[i]=output%mod;
}


int main()
{
    int n, x; cin>>n>>x;
    vector<int> A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    vector<ll> dp(x+1,-1);
    
    cout << func(x,A,dp,n) << endl;
}
    