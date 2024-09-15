#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>v;
queue<int> q1,q2;
int input(int number)
{
    cout<<"Input Entry time and Service time : \nE-T S-T\n";
    for(int i=0; i<number; i++)
    {
        int Enter_time,Srvc_time;
        cin>>Enter_time>>Srvc_time;
        v.push_back(make_pair(Enter_time,Srvc_time));
    }
    sort(v.begin(),v.end());
}
int  calculation(int number)
{
    if(number>=2)
    {

    int srvc1=0,srvc2=0;
    q1.push(1);
    q2.push(2);
    srvc1+=v[0].first+v[0].second-1;
    srvc2+=v[1].first+v[1].second-1;
    for(int i=2; i<number; i++)
    {
        if(srvc1<=srvc2)
        {
            q1.push(i+1);
            srvc1+=v[i].second;
        }
        else
        {
            q2.push(i+1);
            srvc2+=v[i].second;
        }
    }
    }
    else
    {
        q1.push(1);
    }
}
void result()
{
    cout<<"First Queue : ";
    while(!q1.empty())
    {
        cout<<q1.front()<<" ";
        q1.pop();
    }
    cout<<endl;
    cout<<"Second Queue : ";
    while(!q2.empty())
    {
        cout<<q2.front()<<" ";
        q2.pop();
    }
    cout<<endl;
}
int main()
{
    cout<<"Enter the number of people getting services : ";
    int number;
    cin>>number;
    input(number);
    calculation(number);
    result();

    return 0;
}
