#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x; cin>>n>>x;
    vector<vector<int>> dp(n+1,vector<int> (x+1,0));

    vector<int> prices(n);
    vector<int> pages(n);

    for(auto &i:prices)cin>>i;
    for(auto &i:pages)cin>>i;

    //dp[i][j] = max pages for having the choice to use books from book_1 to book_i and having used j dollars

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            dp[i+1][j]=dp[i][j];

            if(prices[i]<=j)
            {
                dp[i+1][j] = max(dp[i+1][j],pages[i]+dp[i][j-prices[i]]);
            }
        }
    }

    cout << dp[n][x] << endl;
}