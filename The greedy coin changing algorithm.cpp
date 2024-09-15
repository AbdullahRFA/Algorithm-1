#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cout<<"Enter the number of coin :" ;
   cin>>n;
   int ara[n];
   for(int i=0;i<n;i++)
   {
       cin>>ara[i];
   }
   sort(ara,ara+n);
   int Money;
   cout<<"Enter the paying amount : ";
   cin>>Money;
   map<int,int>m;
   int count=0,fcount=0;
   while(1)
   {
       for(int i=n-1;i>=0;i--)
       {
           if(ara[i]<=Money)
           {
               count=Money/ara[i];
               Money=Money-(ara[i]*count);
               m[ara[i]]=count;
               fcount+=count;
               if(Money==0)
               {
                 cout<<"\nTotal Number Of coin needed: "<<fcount<<endl;
                 cout<<"Coins are : \n";
                 for(auto x:m)
                 {
                     cout<<x.first<<"->"<<x.second<<" ta\n";
                 }
                  return 0;
               }
           }
       }
   }
}

