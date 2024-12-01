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

FOR SIMULATING ALL CELLS THAT SHARE A WALL WITH CURRENT CELL, GRID IS OF SIZE N*M

int dx[]={-1,0,+1,0};
int dy[]={0,-1,0,+1};

inline bool in(int i,int j){
    return (0<=i&&i<n&&0<=j&&j<m);
}

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
*/

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int mod = 1e9+7;

void solve()
{
    int n, m; cin>>n>>m;
    vector<int> A(n); for(auto &i:A) cin>>i;
    
    vector<vector<ll>> paths(n, vector<ll>(m+1, 0));

    if(A[0]==0)
    {
        for(int i=1;i<=m;i++)
        {
            paths[0][i]=1;
        }
    }
    else
    {
        paths[0][A[0]]=1;
    }

    for(int i=1;i<n;i++)
    {
        if(A[i]==0)
        {
            for(int j=1;j<=m;j++)
            {
                paths[i][j] = (paths[i][j] + paths[i-1][j])%mod;
                if(j-1>0)
                {
                    paths[i][j] = (paths[i][j]+paths[i-1][j-1])%mod;
                }
                if(j+1<=m)
                {
                    paths[i][j]=(paths[i][j]+paths[i-1][j+1])%mod;
                }
            }
        }
        else
        {
            paths[i][A[i]]=(paths[i][A[i]]+paths[i-1][A[i]])%mod;
            if(A[i]-1>0)
            {
                paths[i][A[i]]=(paths[i][A[i]]+paths[i-1][A[i]-1])%mod;
            }
            if(A[i]+1<=m)
            {
                paths[i][A[i]]=(paths[i][A[i]]+paths[i-1][A[i]+1])%mod;
            }
        }
    }

    ll finalnumberofpaths=0;

    for(int i=1;i<=m;i++)
    {
        finalnumberofpaths += paths[n-1][i];
        finalnumberofpaths %= mod;
    }
    cout << finalnumberofpaths << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    //setIO("problemname");

    int t=1; //cin>>t;

    while(t--)
    {
        solve();
    }
}