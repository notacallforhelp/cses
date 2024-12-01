#include <bits/stdc++.h>

using namespace std;

const int m = 1e7+10;
int hsh[m];

int main()
{
    int n; cin>>n; int m; cin>>m;

    vector<int> A(n+2);

    A[0]=0;
    A[n+1]=n+1;

    hsh[0]=0;
    hsh[n+1]=n+1;

    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
        hsh[A[i]]=i;
    }


    int result = 1;
    for(int i=1;i<=n-1;i++)
    {
        if(hsh[i]>hsh[i+1])
        {
            ++result;
        }
    }

    //cout << result << endl;

    while(m--)
    {
        int a, b; cin>>a>>b;

        int ele1 = A[a];
        int ele2 = A[b];

        int b4ele1,b4ele2;
        int a4ele1,a4ele2;

        b4ele1 = ele1-1;
        b4ele2 = ele2-1;
        a4ele1 = ele1+1;
        a4ele2 = ele2+1;

        int p1 = hsh[b4ele1];
        int p2 = hsh[b4ele2];

        int p3 = hsh[a4ele1];
        int p4 = hsh[a4ele2];

        //cout << p1 << " "<<p3<<" " << p2 <<" "<<p4<< endl;

        //result==1?result:--result;

        if(a<p1&&b>p1)
        {
            --result;
        }
        else if(a>p1&&b<p1)
        {
            ++result;
        } 
        
        if(a<p3&&b>p3)
        {
            ++result;
        }
        else if(a>p3&&b<p3)
        {
            --result;
        }

        if(b<p2&&a>p2)
        {
            --result;
        }
        else if(b>p2&&a<p2)
        {
            ++result;
        }

        if(b<p4&&a>p4)
        {
            ++result;
        }
        else if(b>p4&&a<p4)
        {
            --result;
        }

        if(a<p1&&b==p1)
        {
            --result;
        }
        else if(a>p1&&b==p1)
        {
            ++result;
        }
        /*else if(b<p2&&a==p2)
        {
            --result;
        }
        else if(b>p2&&a==p2)
        {
            ++result;
        }*/

        if(a<p3&&b==p3)
        {
            ++result;
        }
        else if(a>p3&&b==p3)
        {
            --result;
        }
        /*else if(b<p4&&a==p4)
        {
            ++result;
        }
        else if(b>p4&&a==p4)
        {
            --result;
        }*/

        swap(A[b],A[a]);

        hsh[ele1]=b;
        hsh[ele2]=a;

        cout << result << endl;

        /*for(auto ele:A)
        {
            cout << ele << " " ;
        }
        cout << endl;*/
    }
}