#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    map<int,int> enter;

    map<int,int> exit;

    vector<int> nums;

    for(int i=0;i<n;i++)
    {
        int x, y; cin>>x>>y;

        enter[x]=1;
        exit[y]=1;

        nums.push_back(x);
        nums.push_back(y);
    }


    sort(nums.begin(),nums.end());

    int global=0;
    int local=0;

    for(int i=0;i<nums.size();i++)
    {
        if(enter[nums[i]]) ++local;
        if(exit[nums[i]]) --local;

        global = max(global,local);
    }

    cout << global << endl;
}