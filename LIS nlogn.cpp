#include<bits/stdc++.h>
using namespace std;
#define ll      long long int
int main()
{
    ll n,length,last;
    cout<<"Enter the Number of elements: ";
    cin >> n;
    vector<ll>v(n),sequence;
    for(auto &it:v)cin>>it;
    sequence.push_back(v[0]);
    for(ll i=1; i<n; i++)
    {
        auto it= lower_bound(sequence.begin(),sequence.end(),v[i]);
        if(it==sequence.end()) sequence.push_back(v[i]);
        else *it=v[i];
    }
    length=sequence.size();
    cout<<"Length of LIS is : "<<length<<endl;
    cout<<"The Longest Increasing Sequence is : ";
    for(auto it:sequence) cout<<it<<' ';
    cout<<endl;
}
