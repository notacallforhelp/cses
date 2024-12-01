#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    vector<int> A(n);

    int ct = 0;

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    multiset<int> S;

    for(int i=0;i<n;i++)
    {
        auto it = S.upper_bound(A[i]);
        if(it==S.end())
        {
            S.insert(A[i]);
        }
        else
        {
            S.erase(it);
            S.insert(A[i]);
        }
    }

    cout << S.size() << endl;

}