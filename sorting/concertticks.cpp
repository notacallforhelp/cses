#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;

    vector<int> A(n);
    vector<int> B(m);
    set<pair<int,int>> sortedTickets;

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        sortedTickets.insert({A[i],i});
    }

    for(int i=0;i<m;i++)
    {
        cin>>B[i];
    }

    for(int i=0;i<m;i++)
    {
        auto match = sortedTickets.lower_bound({B[i]+1,0});
        if(match==sortedTickets.begin())
        {
            cout << -1 << endl;
        }
        else
        {
            match --;
            cout << (*match).first << endl;
            sortedTickets.erase(match);
        }
    }
}