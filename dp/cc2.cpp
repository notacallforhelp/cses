#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main()
{
    int n,x; cin>>n>>x;
    vector<int> coins(n); for(auto &i:coins)cin>>i;

    vector<int> dp(x+1,0);

    dp[0]=1;

    //dp[i] stores the number of distinct ways to make sum i using the coins

    //idea is all c0, then only c1s to cns.

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            if(j-coins[i]>=0)
            {
                dp[j]+=dp[j-coins[i]];
                dp[j]%=mod;
            }
        }
    }
    cout << dp[x]%mod << endl;
}