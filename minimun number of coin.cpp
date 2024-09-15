#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const   ll  N=1e6;
ll ara[N],dp[N];
ll coinChange(ll k,vector<ll>&v)
{
    if(k==0)return 0;
    if(dp[k]!=-1)return dp[k];
    ll ans=INT_MAX;
    for(auto x: v)
    {
        if(k-x>=0)
            ans=min(ans,coinChange(k-x,v)+1);
    }
    return dp[k]=ans;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    ll n,k;
    cin>>n>>k;
    vector<ll>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    ll ans=coinChange(k,v);
    if(ans==INT_MAX)cout<<"-1"<<endl;
    else cout<<"Minimum number of coid required is "<<ans<<endl;
}
