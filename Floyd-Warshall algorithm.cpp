#include<bits/stdc++.h>
using namespace std;
#define ll      long long int
#define MAX 100000000
int main()
{
    int n;
    cout<<"Enter the number of node : ";
    cin>>n;
    ll ara[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>ara[i][j];
            if(ara[i][j]==0)
            {
                ara[i][j]=MAX;
            }
        }
    }
    cout<<"Graph represented matrix : \n";
    for(int i=0; i<n; i++)
    {
        cout<<"\t";
        for(int j=0; j<n; j++)
        {
            if(ara[i][j]==MAX)
                cout<<"inf"<<" ";
            else
                cout<<ara[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                ara[i][j]=min(ara[i][k]+ara[k][j],ara[i][j]);
            }
        }
    }
cout<<"Shortest Path: \n";
    for(int i=0; i<n; i++)
    {cout<<"\t";
        for(int j=0; j<n; j++)
        {
            if(ara[i][j]==MAX)
                cout<<"inf"<<" ";
            else
                cout<<ara[i][j]<<" ";
        }
        cout<<endl;
    }
}
