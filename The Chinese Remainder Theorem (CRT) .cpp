#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
ll solve(ll var_Mn[],ll mod_v[],ll i)
{
    ll x=1;
    while(true)
    {
        ll rem=(var_Mn[i]*x)%mod_v[i];
        if(rem==1)
        {
            return x;
        }
        x++;
    }
}
int main()
{
    ll n;
    cout<<"Enter the number of equation : ";
    cin>>n;
    ll ara[n],mod_v[n],var_Mn[n],var_M_in[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Enter the value of a"<<i+1<<" = ";
        cin>>ara[i];
    }
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter the value of m"<<i+1<<" = ";
        cin>>mod_v[i];
    }
    ll M=1;
    for(int i=0; i<n; i++)
    {
        M*=mod_v[i];
    }
    for(int i=0; i<n; i++)
    {
        var_Mn[i]=(M/mod_v[i]);
    }
     for(int i=0;i<n;i++)
    {
        var_M_in[i]=solve(var_Mn,mod_v,i);
    }
    ll X=0;
    for(int i=0;i<n;i++)
    {
        X+=ara[i]*var_Mn[i]*var_M_in[i];
    }
    cout<<"\nValue of X = ";
    cout<<X%M<<endl;
}
/*
Enter the number of equation : 3
Enter the value of a1 = 2
Enter the value of a2 = 3
Enter the value of a3 = 2

Enter the value of m1 = 3
Enter the value of m2 = 5
Enter the value of m3 = 7

Value of X = 23




Input Reading: O(n)
Calculation of 'M': O(n)
Calculation of 'var_Mn' Array: O(n)
Calculation of 'var_M_in' Array: O(n * max(mod_v[i]))
Calculation of 'X': O(n)
Output: O(1)

So, the overall time complexity of this code is approximately

 O(n * max(mod_v[i])) in the worst case,

 where 'n' is the number of equations,
 and 'max(mod_v[i])' is the maximum value in the 'mod_v' array.
*/
