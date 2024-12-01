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