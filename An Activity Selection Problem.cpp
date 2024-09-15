#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>v(n);
    for(int i=0; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        v[i].first=y;
        v[i].second=x;
    }
    sort(v.begin(),v.end());
    cout<<endl;
    cout<<v[0].second<<" "<<v[0].first<<endl;
    int j=0;
    for(int i=1; i<n; i++)
    {
        if(v[j].first<=v[i].second)
        {
            j=i;
            cout<<v[i].second<<" "<<v[i].first<<endl;
        }
    }
}
