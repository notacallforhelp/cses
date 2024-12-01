#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    int n, k; cin>>n>>k;

    vector<int> current(n);

    for(int i=1;i<=n;i++)
    {
        current[i-1]=i;
    }
    int skipped=0;
    //k=k%n;

    while(current.size()>1)
    {
        vector<int> survivors;
        k=k%current.size();

        for(int i=0;i<current.size();i++)
        {
            if(skipped==k)
            {
                cout << current[i] << " ";
                skipped=0;
                continue;
            }
            ++skipped;
            survivors.push_back(current[i]);
        }
        /*cout << endl;
        for(auto ele:survivors)
        {
            cout << ele << " ";
        }
        cout << endl;*/
        current.clear();
        current = survivors;
        survivors.clear();
    }
    if(!current.empty())
    {
        cout << current[0]<< endl;
    }
    //cout << current[0] << endl;
}