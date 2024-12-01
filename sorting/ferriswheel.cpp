#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int n, x;
    cin>>n>>x;

    vector<ll> A(n);

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    sort(A.begin(),A.end());

    int r = A.size()-1;
    int l = 0;
    int count = 0;

    while(l<=r)
    {
        if(l==r)
        {
            ++count;
            ++l;
        }
        else
        {
            if(A[l]+A[r]>x)
            {
                ++count;
                --r;
            }
            else
            {
                ++count;
                ++l;
                --r;
            }
        }
    }

    cout << count << endl;


}