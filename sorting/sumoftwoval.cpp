#include <bits/stdc++.h>

using namespace std;

map<int,int> M;

int main()
{
    int n, x; cin>>n>>x;

    

    map<int,set<int>> pos;


    for(int i=0;i<n;i++)
    {
        int k; cin>>k;
        ++M[k];
        pos[k].insert(i+1);
    }

    /*for(auto ele:M)
    {
        cout << ele.first << " " << ele.second << endl;
    }

    for(auto ele:pos)
    {
        cout << ele.first << "is at ";
        for(auto m:ele.second)
        {
            cout << m << " ";
        }
        cout << endl;
    }*/

    for(auto it=M.begin();it!=M.end();it++)
    {
        int valathand = it->first;
        if(M[valathand]==0) continue;
        //cout << valathand << endl;
        if((x-valathand)!=valathand)
        {
            if(M[x-valathand]>0)
            {
                auto it = pos[valathand].begin();
                auto it2 = pos[x-valathand].begin();
                cout << *(it) << " " << *(it2) << endl;
                return 0;
            }
        }
        else
        {
            if(M[x-valathand]>1)
            {
                //cout << x << endl;
                auto it = pos[valathand].begin();
                auto it2 = pos[valathand].begin();
                ++it2;
                cout << *(it) << " " << *(it2) << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}