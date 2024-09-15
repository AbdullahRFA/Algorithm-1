#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of Items : ";
    cin>>n;
    int b[n],w[n],vpml[n];
    cout<<"Enter the positive benefits one by one : ";
    for(int i=0; i<n; i++)
    {
        cin>>b[i];
    }
    cout<<"Enter the positive weight one by one : ";
    for(int i=0; i<n; i++)
    {
        cin>>w[i];
    }
    for(int i=0; i<n; i++)
    {
        vpml[i]=b[i]/w[i];
    }
    map<int,int>m;
    for(int i=0; i<n; i++)
    {
        m[vpml[i]]=w[i];
    }

    sort(vpml,vpml+n);
    cout<<"Enter the capacity of knapsack :";
    int cp;
    cin>>cp;
    int W=0,profit=0;

    while(1)
    {
        for(int i=n-1; i>=0; i--)
        {
            if(m[vpml[i]]<=cp)
            {
                cp-=m[vpml[i]];
                profit+=(vpml[i]*m[vpml[i]]);

                if(cp==0)
                {
                    cout<<"\nTotal Profit : "<<profit<<endl;
                    return 0;
                }
                else
                {
                    continue;
                }
            }
            else
            {

                profit+=(cp*vpml[i]);

                cout<<"\nTotal Profit : "<<profit<<endl;
                return 0;

            }
        }
    }
}

