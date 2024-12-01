#include <bits/stdc++.h>
using namespace std;

const int M = 1e6;
typedef long long int ll;
int hsh[M];
int pf[M];

int main()
{
    int n; cin>>n;
    vector<int> A(n);

    for(auto &ele:A) cin>>ele;

    ll p1=0;
    ll p2=0;

    set<int> S;
    
    ll global = 0;

    while(p1<n&&p2<n)
    {
        while(p2<n&&!S.count(A[p2]))
        {
            S.insert(A[p2]);
            global = max(global,p2-p1+1);
            ++p2;
        }
        while(p2<n&&S.count(A[p2]))
        {
            S.erase(A[p1]);
            ++p1;
        }
    }


    cout << global << endl;
}