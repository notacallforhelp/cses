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

/*void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}*/

int tilings[1001][1ll<<10];
int n,m;
const int MOD = 1e9+7;

void fill_column(int column,int idx,int curr_mask,int next_mask)
{
    if(idx==n)   //have filled whole column
    {
        //propagate the number of ways of current mask to the next mask in the following column
        tilings[column+1][next_mask]= (tilings[column+1][next_mask]+tilings[column][curr_mask])%MOD;
        return;
    }

    //check if current tile is full, if full go to next index
    if((1ll<<idx)&(curr_mask))
    {
        fill_column(column,idx+1,curr_mask,next_mask);
    }
    else  //not full, so can put a tile
    {
        //putting horizontal tile [transition to next tile, but turn on the bit for the next mask]
        fill_column(column,idx+1,curr_mask,next_mask|(1ll<<idx));
        //put vertical tile, only possible if idx is stricly less than n-1 and the next tile is empty
        if(idx+1<n&&(!(curr_mask&(1ll<<(idx+1)))))
        {
            //allows us to skip 2 tiles and no need to update next mask cuz nothing goes in the adj column
            fill_column(column,idx+2,curr_mask,next_mask);
        }
    }
}

void solve()
{
    cin>>n>>m;
    tilings[0][0]=1;  // one way to have an empty grid
    for(int column=0;column<m;column++)   //process all columns one by one
    {
        for(int mask=0;mask<(1ll<<n);mask++)
        {
            if(tilings[column][mask]>0)   //means there is a way to reach this specific config,so we need to fill the column
            {
                fill_column(column,0,mask,0);
            }
        }
    }

    cout << tilings[m][0]<<endl;
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