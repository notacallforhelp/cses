#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main()
{
    int n,x; cin>>n>>x;

    vector<int> coins(n); for(auto &i:coins)cin>>i;
    vector<vector<int>> dp(n+1,vector<int> (x+1,0));

    //dp[i][k] means coins from c_i to c_n can only be used to construct a sum k
    // goal being packing all c1s together and so on

    for(int i=0;i<n;i++)
    {
        dp[i][0]=1;
    }

    //dp[i][k] = dp[i][k-c_i] + dp[i+1][k]

    for(int i=n-1;i>=0;i--)
    {
        for(int k=1;k<=x;k++)
        {
            int skipped = dp[i+1][k];
            int picked=0;
            if(k-coins[i]>=0)
            {
                picked = dp[i][k-coins[i]];
            }

            dp[i][k]= (skipped+picked)%mod;
        }
    }

    cout << dp[0][x] << endl;
}