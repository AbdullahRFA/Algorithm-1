#include<bits/stdc++.h>
using namespace std;
#define     ll      long long int
vector<ll>meet_in_the_middle(vector<ll>&v,int c,int n)
{
    vector<ll>temp;
    for(int i=0; i<(1<<n); i++)
    {
        ll sum=0;
        for(int j=0; j<n; j++)
        {
            if(i&(1<<j))
            {
                sum+=v[j+c];
            }
        }
        temp.push_back(sum);
    }
    return temp;
}
int main()
{
    ll t;
    t=1;
    while(t--)
    {
        ll n,x;
        cin>>n>>x;
        vector<ll>v(n);
        for(int i=0; i<n; i++)cin>>v[i];
        vector<ll>v1,v2;
        v1=meet_in_the_middle(v,0,n/2);
        v2=meet_in_the_middle(v,n/2,(n+1)/2);
//        for(auto x:v1)cout<<x<<" ";
//        cout<<endl;
//        for(auto x:v1)cout<<x<<" ";
//        cout<<endl;

        sort(v2.begin(),v2.end());
        ll ans=0;
        for(auto it:v1)
        {
            ans+=upper_bound(v2.begin(),v2.end(),x-it)-lower_bound(v2.begin(),v2.end(),x-it);
        }
        cout<<ans;

    }

}
