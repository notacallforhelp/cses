#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


#define int long long
typedef long long ll;
typedef long double ld;

//ordered_sets
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

//struct for range 
struct range
{
    int l,r,index;
    bool operator < (const range &other) const
    {
        if(l==other.l)
            return r>other.r;
        return l < other.l;
    }
};

/*
FOR SIMULATING ALL CELLS THAT SHARE A WALL WITH CURRENT CELL, GRID IS OF SIZE N*M

int dx[]={-1,0,+1,0};
int dy[]={0,-1,0,+1};

inline bool in(int i,int j){
    return (0<=i&&i<n&&0<=j&&j<m);
}


binary exp 

ll binpow(ll a,ll b)
{
    if(b==0)
    {
        return 1;
    }
    if(b%2)
    {
        return (a*binpow(a,b-1))%mod;
    }
    return binpow((a*a)%mod,b/2);
}

ceil 

ll ceil2(ll a, ll b) {
    if (a == 0) return 0;
    return (a - 1)/b + 1;
}

COMBINATORICS TEMPLATE 

const int N = 2e5 + 5, mod = 1e9 + 7;
int64_t fact[N];
int64_t pw(int64_t a, int64_t b) {
	int64_t r = 1;
	while(b > 0) {
		if(b & 1) r = (r * a) % mod;
		b /= 2;
		a = (a * a) % mod; 
	}
	return r;
}
int64_t C(int64_t n, int64_t k) {
	if(n < k) return 0LL;
	return (fact[n] * pw((fact[n - k] * fact[k]) % mod, mod - 2)) % mod;
}

void find_divisors()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=i;j<=N;j+=i)
        {
            divisors[j].push_back(i);
        }
    }
}

DFS

vector<vector<int>> adj(n);
vector<bool> visited(n);

void dfs(int current_node) {
	if (visited[current_node]) { return; }
	visited[current_node] = true;

	for (int neighbor : adj[current_node]) { dfs(neighbor); }
}

SIEVE

void sieve(int n,vector<bool> &prime)
{
    for(int i=2;i*i<=n;i++)
    {
        if(prime[i]==true)
        {
            for(int p=i*i;p<=n;p+=i)
            {
                prime[p]=false;
            }
        }
    }
}
prime[0]=prime[1]=false;

*/

/*void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}*/

void solve()
{
    int n; cin>>n;
    vector<int> A(n); for(auto &i:A)cin>>i;

    vector<vector<int>> dp(n,vector<int> (n,0));

    //dp[i][j] is the maximum difference between the first player and second player score
    // that can be created for the player who starts first

    // so dp[i][i] is just A[i] as its only one element, P1 chooses this element, so dp[i][i]=A[i]

    // dp[i][j] = max(A[i]-dp[i+1][j],A[j]-dp[i][j-1])

    // the first part A[i]-dp[i+1][j]
    // A[i] is the element P1 is choosing,
    // so the interval of [i+1,j] the first chance goes to P2
    // so the dp[i+1][j] is esentially S2-S1
    // so A[i] - (dp[i+1][j]) = A[i] + S1 - S2, which ultimately becomes S1-S2 as A[i] is part of S1
    // thus preserving dp state
    // this represent picking element from left

    // the second part A[j]-dp[i][j-1] is done the same way, but ele
    // is first picked from right

    // the final subproblem is dp[0][n-1] which is esentially S1-S2 over the whole array
    // S1+S2 is given by sum of all elements denoted by say sum variable

    // so sum + dp[0][n-1] == 2*S1
    // so S1 == (sum+dp[0][n-1])/2

    int sum = 0;

    for(int i=0;i<n;i++)
    {
        sum += A[i];
        dp[i][i]=A[i];
    }

    for(int i=n-1;i>=0;i--)
    {
        for(int j=i+1;j<n;j++)
        {
            int left = A[i]-dp[i+1][j];
            int right = A[j]-dp[i][j-1];

            dp[i][j]=max(left,right);
        }
    }

    int output = (dp[0][n-1]+sum)/2;

    cout << output << endl;

    
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    //setIO("problemname");

    int t=1; //cin>>t;

    while(t--)
    {
        solve();
    }

    return 0;
}