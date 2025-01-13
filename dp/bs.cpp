#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x; cin>>n>>x;

    vector<int> prices(n);
    vector<int> pages(n);
    for(auto &i:prices)cin>>i;
    for(auto &i:pages)cin>>i;

    vector<vector<int>> dp(n+1,vector<int> (x+1,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            if(j+prices[i]<=x)
            {
                dp[i+1][j+prices[i]]=max(dp[i+1][j+prices[i]],dp[i][j]+pages[i]);
            }
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
        }
    }

    cout << dp[n][x] << endl;
}