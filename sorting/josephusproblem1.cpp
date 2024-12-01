#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);
    int n; cin>>n;

    vector<int> A(n);

    for(int i=1;i<=n;i++)
    {
        A[i-1]=i;
    }

    while(A.size()>1)
    {
        vector<int> survivors;

        for(int i=0;i<A.size();i++)
        {
            if(i%2==0)
            {
                survivors.push_back(A[i]);
            }
            else
            {
                cout << A[i] << " ";
            }
        }

        if(A.size()%2==0)
        {
            A=survivors;
        }
        else
        {
            int val = survivors.back();
            survivors.pop_back();

            A.clear();
            A.push_back(val);
            for(auto &ele: survivors)
            {
                A.push_back(ele);
            }
        }
    }
    cout << A[0] << endl;
}