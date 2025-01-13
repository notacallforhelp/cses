#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e9;  //max value ever could be x = 1e6 , and using all 1s, so cant ever cross 1e6

int32_t main()
{
    int n,x; cin>>n>>x;

    vector<int> coins(n); for(auto &i:coins)cin>>i;

    vector<int> dp(x+1,INF);   // dp[i] means to construct sum i, it will store the min amnt of coins needed

    dp[0]=0;

    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i+coins[j]<=x)
            {
                dp[i+coins[j]]=min(dp[i+coins[j]],dp[i]+1);
            }
        }
    }
    if(dp[x]==INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[x] << endl;
    }
}