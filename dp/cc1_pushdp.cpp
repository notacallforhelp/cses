#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9+7;

int32_t main()
{
    int n,x; cin>>n>>x;

    vector<int> coins(n); for(auto &i:coins)cin>>i;

    vector<int> dp(x+1,0);   // dp[i] means the total number of ways we can construct the sum i using the coins given as many number of times

    dp[0]=1;

    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i+coins[j]<=x)
            {
                dp[i+coins[j]] += dp[i];
                dp[i+coins[j]] %= mod;
            }
        }
    }
    
    cout << dp[x]%mod << endl;
}