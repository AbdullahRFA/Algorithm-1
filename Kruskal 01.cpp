#include<bits/stdc++.h>
using namespace std;
int edges,nodes;
vector<pair<int,int>>g[100];
vector<pair<int,pair<int ,int> > >Edgelist;
int dsu[100];
int findparent(int u)
{
    if(dsu[u]==u)return u;
    return dsu[u]=findparent(dsu[u]);
}
int main()
{
    cin>>nodes>>edges;
    char x,y;
    int w;
    for(int i=1;i<=edges;i++)
    {
        cin>>x>>y>>w;
        int u=x-'a'+1;
        int v=y-'a'+1;
        g[u].push_back(make_pair(v,w));
        if(u>v)swap(u,v);
        pair<int,pair<int,int> > e = make_pair(w,make_pair(u,v));
        Edgelist.push_back(e);
    }
    sort(Edgelist.begin(),Edgelist.end());
    for(int i=1;i<=nodes;i++)dsu[i]=i;
    int totalcost=0;
    for(int i=0;i<Edgelist.size();i++)
    {
        pair<int ,int>e=Edgelist[i].second;
        int edgeWight=Edgelist[i].first;
        int u=e.first;
        int v=e.second;
        int paru=findparent(u);
        int parv=findparent(v);
        if(paru==parv)
        {
            cout<<"Endge between "<<char(u+'a'-1)<<" "<<char(v+'a'-1)<<" Ignored"<<endl;
        }
        else
        {
             cout<< "Edge("<<char(u+'a'-1 ) <<", "<<char(v+'a'-1)<<"), --> "<<edgeWight<<endl ;
            totalcost+=edgeWight;
            if(paru>parv)swap(paru,parv);
            dsu[parv]=paru;
        }
    }
            cout<<"Total cost = "<<totalcost<<endl;
}
/*
The overall time complexity of the code is dominated by
the sorting step and is O(edges * log(edges)).
The space complexity is O(nodes + edges) due
to the space required for the adjacency list representation,
DSU data structure, and the edge list.

9 14
g h 1
c i 2
f g 2
a b 4
c f 4
g i 6
c d 7
i h 7
a h 8
b c 8
d e 9
e f 10
b h 11
d f 14

*/


/*
a b c d e f g h i
1 2 3 4 5 6 7 8 9

9 14
1 2 4
1 8 8
2 3 8
2 8 11
3 4 7
3 6 4
3 9 2
4 5 9
4 6 14
5 6 10
6 7 2
7 8 1
7 9 6
8 9 7



5 9
 1 2 7
 1 4 2
 2 4 2
 4 2 3
 2 3 1
 4 3 8
 4 5 5
 3 5 4
 5 3 5


 The overall time complexity of the code is dominated by the sorting step
 and is O(edges * log(edges)). The space complexity is O(nodes + edges)
 due to the space required for the adjacency list representation, DSU data structure,
 and the edge list.

*/
