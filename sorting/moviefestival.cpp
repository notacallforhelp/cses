#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int> &a,pair<int,int> &b)
{
    return (a.second<b.second);
}

int main()
{
    int n;
    cin>>n;

    vector<pair<int,int>> A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i].first>>A[i].second;   // stored as {endtime,starttime}
    }

    sort(A.begin(),A.end(),cmp);

    int LMFT=-1;
    int local=0;

    for(int i=0;i<n;i++)
    {
        if(A[i].first>=LMFT)
        {
            LMFT = A[i].second;
            ++local;
        }
    }

    cout << local << endl;

}