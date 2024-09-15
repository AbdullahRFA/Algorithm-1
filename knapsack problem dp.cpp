#include <bits/stdc++.h>
using namespace std;
#define ll      long long

ll Weight[100],Values[100005],check[105][1005];
ll W,w,n;

ll calculate(ll idx,ll weight_left)
{
    if(idx<0 || weight_left<=0 ) return 0;
    if(check[idx][weight_left]!=-1) return check[idx][weight_left];
    ll result=calculate(idx-1,weight_left);
    if(weight_left-Weight[idx]>=0) result=max(result,calculate(idx-1,weight_left-Weight[idx])+Values[idx]);
    else result=max(result,calculate(idx-1,weight_left));
    return check[idx][weight_left] =result;
}

void print(ll x,ll y)
{
    if(x==0 || y==0) return;

    if(check[x][y]>check[x-1][y])
    {
        cout<<x<<' ';
        print(x-1,y-Weight[x]);
    }
    else print(x-1,y);
}

int main()
{
    memset(check,-1,sizeof(check));
    cin >> n>>W;
    for (ll i = 1; i <= n; i++) cin>>Weight[i]>>Values[i];
    cout<<"Maximum Profit is : "<<calculate(n,W)<<endl;
    cout<<"Selected Items no. are : ";

    print(n,W);
    return 0;
}
