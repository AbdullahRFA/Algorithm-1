#include <bits/stdc++.h>
using namespace std;
#define ll          long long
vector<ll>v;
ll check[100005];
ll n,a,seq;
stack<ll>s;
vector<ll>parent(100);

ll lng_sub_sqnc(ll i)
{
    if(i==0) return -100000;
    if(check[i]!=-1) return check[i];
    ll res=1;
    for(ll j=i-1; j>=0; j--)
    {
        if(v[j]<v[i])
        {
            ll p=lng_sub_sqnc(j)+1;
            if(res<p)
            {
                parent[i]=j;
                res=p;
            }
        }
    }
    return check[i]=res;
}

void print(ll p)
{
    if(p==0) return ;
    s.push(v[p]);
    print(parent[p]);
    while(!s.empty())
    {
        cout<<s.top()<<' ';
        s.pop();
    }
}
int main()
{
    memset(check,-1,sizeof(check));
    cout<<"Enter the Number of elements: ";
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin>>a;
        v.push_back(a);
    }
    ll res=1;
    for (ll i = 0; i < n; i++)
    {
        ll p=lng_sub_sqnc(i);
        if(res<p)
        {
            res=p;
            seq=i;
        }
    }

    cout<<"Length of LIS is : "<< res<<endl;
    cout<<"The Longest Increasing Sequence is : ";
    print(seq);
    cout<<endl;
    return 0;
}

