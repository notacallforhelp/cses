#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main()
{
    int n,x; cin>>n>>x;

    vector<int> coins(n); for(auto &i:coins)cin>>i;
    vector<vector<int>> dp(n+1,vector<int> (x+1,0));

    vector<int> nextState(x+1,0);
    nextState[0]=1;

    //dp[i][k] means coins from c_i to c_n can only be used to construct a sum k
    // goal being packing all c1s together and so on

    //dp[i][k] = dp[i][k-c_i] + dp[i+1][k]

    for(int i=n-1;i>=0;i--)
    {
        vector<int> currentState(x+1,0);
        currentState[0]=1;
        for(int k=1;k<=x;k++)
        {
            int skipped = nextState[k];
            int picked=0;
            if(k-coins[i]>=0)
            {
                picked = currentState[k-coins[i]];
            }

            currentState[k]= (skipped+picked)%mod;
        }
        nextState = currentState;
    }

    cout << nextState[x] << endl;
}