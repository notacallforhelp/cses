#include <bits/stdc++.h>

using namespace std;

const int m = 1e7+10;
int hsh[m];

int main()
{
    int n; cin>>n;

    vector<int> A(n);

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        hsh[A[i]]=i;
    }


    int ct = 1;
    for(int i=1;i<=n-1;i++)
    {
        if(hsh[i]>hsh[i+1])
        {
            ++ct;
        }
    }

    cout << ct << endl;
}