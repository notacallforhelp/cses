#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


typedef long long int ll;
typedef long double ld;

//ordered_sets
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

//struct for range 
struct range
{
    ll l,r,index;
    bool operator < (const range &other) const
    {
        if(l==other.l)
            return r>other.r;
        return l < other.l;
    }
};

/*binary search template

while(hi-low>0)
    {
        ll mid = (low+hi)/2;
        ll products = 0;
        for(int i=0;i<n;i++)
        {
            products += min(mid/A[i],(ll)1e9);
        }
        if(products>=k)
        {
            if(mid<answer)
            {
                answer = mid;
            }
            hi = mid;
        }
        else
        {
            low = mid+1;
        }
    }

*/

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    int n; cin>>n;
    vector<int> dp(n+1,0);
    dp[0]=0;
    /*for(int i=1;i<=9;i++)
    {
        dp[i]=1;
    }*/
    for(int i=1;i<=n;i++)
    {
        set<int> digits;
        int temp=i;
        while(temp)
        {
            if(temp%10!=0)
            {
                digits.insert(temp%10);
            }
            temp=temp/10;
        }
        for(auto ele:digits)
        {
            if(dp[i]==0)
            {
                dp[i]=dp[i-ele]+1;
            }
            dp[i]=min(dp[i-ele]+1,dp[i]);
        }
        /*for(int j=0;j<=9;j++)
        {
            //cout << "hi" << endl;
            if(digits.count(j)==0)
            {
                continue;
            }
            if(dp[i]==0)
            {
                dp[i]=dp[i-j]+1;
            }
            dp[i]=min(dp[i-j]+1,dp[i]);
        }*/
    }
    cout << dp[n] << endl;
}