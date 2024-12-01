#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct P{
    ll x, y;
    void read(){
        cin>>x>>y;
    }
    P operator -(const P& b) const {
        return P{x-b.x,y-b.y};
    }
    void operator -=(const P& b){
        x-=b.x;
        y-=b.y;
    }
    ll operator*(const P& b)const{
        return x*b.y-y*b.x;
    }
    ll triangle(const P&b, const P&c) const{
        return (b-*this)*(c-*this);
    }
};

int main()
{
    int n; cin>>n;

    vector<P> polygon(n);

    for(auto &ele: polygon)
    {
        ele.read();
    }
    ll area = 0;

    for(int i=0;i<n;i++)
    {
        area += polygon[i]*polygon[i+1==n?0:i+1];
    }
    cout << abs(area) << endl;
}