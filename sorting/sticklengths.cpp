#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int ceil2(int a, int b) {
    int c=a/b;
    if((a % b)!=0) c++;
    return c;
}

int main()
{
    int n; cin>>n;

    vector<ll> A(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
    }

    sort(A.begin(),A.end());

    if(n&1)
    {
        ll median = A[(n+1)/2];
        ll output = 0;

        for(int i=1;i<=n;i++)
        {
            output += abs(A[i]-median);
        }

        cout << output << endl;
    }
    else
    {
        ll median_f = (A[n/2]+A[n/2+1])/2;
        ll median_c = ceil2(A[n/2]+A[n/2+1],2);

        ll output1 = 0;
        ll output2 = 0;

        for(int i=1;i<=n;i++)
        {
            output1 += abs(A[i]-median_f);
            output2 += abs(A[i]-median_c);
        }

        cout << min(output1,output2) << endl;
    }
    return 0;
}