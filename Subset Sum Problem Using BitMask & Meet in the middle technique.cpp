#include<bits/stdc++.h>
using namespace std;
vector<int> solve(int  ara[],int n,int c)
{
    vector<int>temp;
    for(int i=1; i<(1<<n); i++)
    {
        int sum=0;
        for(int j=0; j<n; j++)
        {
            if((i&(1<<j))!=0)sum+=ara[j];
        }
        temp.push_back(sum);
    }
    return temp;
}
int main()
{
    int n;
    cin>>n;
    int ara[n];
    for(int i=0; i<n; i++)cin>>ara[i];
    int sum;
    cin>>sum;
    int count=0;
    vector<int>v1,v2;

    v1=solve(ara,n/2,0);
    v2=solve(ara,(n+1)/2,n/2);
    sort(v2.begin(),v2.end());
    for(auto x:v1)
    {
        count+=upper_bound(v2.begin(),v2.end(),sum-x)-lower_bound(v2.begin(),v2.end(),sum-x);
    }
    cout<<count<<endl;
}
