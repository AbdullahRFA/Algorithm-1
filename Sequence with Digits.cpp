#include<bits/stdc++.h>
using namespace std;
#define     ll      long long int
ll solve(ll a)
{
    ll mn=INT_MAX,mx=INT_MIN;
    while(a!=0)
    {
        ll rem=a%10;
        a/=10;
        mn=min(mn,rem);
        mx=max(mx,rem);
    }
    return mn*mx;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a, k;
        cin>>a>>k;
        k--;
        while(k--)
        {
            ll res =solve(a);
            if(res==0)break;
            a+=res;
        }
        cout<<a<<endl;
    }
}
