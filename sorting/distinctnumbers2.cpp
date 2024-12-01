#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;

    vector<int> S(n);

    for(int i=0;i<n;i++)
    {
        cin>>S[i];
    }

    sort(S.begin(),S.end());

    int count = 1;

    for(int i=0;i<n-1;i++)
    {
        if(S[i]!=S[i+1])
        {
            ++count;
        }
    }

    cout << count << endl;
}