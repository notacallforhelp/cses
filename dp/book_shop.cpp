#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    int n,x; cin>>n>>x;
    vector<int> price(n); 
    vector<int> pages(n);
    for(auto &i:price)cin>>i;
    for(auto &i:pages)cin>>i;

    vector<vector<int>> dp(n+1,vector<int> (x+1,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            if(j+price[i]<=x)
            {
                dp[i+1][j+price[i]]=max(dp[i+1][j+price[i]],dp[i][j]+pages[i]);
            }
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
        }
    }

    cout << dp[n][x] << endl;

}