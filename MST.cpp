//#include <bits/stdc++.h>
//using namespace std;
//
//vector<pair<int,int> > graph[10];
//int vis[100];
//int par[100];
//#define inf 1000
//int node, edge;
//int cost[100];
//priority_queue< pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>> PQ;
//
//void Prims(int src)
//{
//    PQ.push(make_pair(0, src));
//    for(int i = 0; i <= 10; i++) cost[i] = inf;
//    int mst = 0;
//
//    while(!PQ.empty())
//    {
//        int cst = PQ.top().first;
//        int u = PQ.top().second;
//        PQ.pop();
//
//        if(vis[u] == 1) continue;
//        mst += cst;
//
//        vis[u] = 1;
//        for(int i = 0; i < graph[u].size(); i++)
//        {
//            int v = graph[u][i].first;
//            int w = graph[u][i].second;
//
//            if(cost[v] > w)
//            {
//                cost[v] = w;
//                par[v] = u;
//                PQ.push(make_pair(cost[v], v));
//            }
//        }
//    }
//    cout << "The minimum spanning tree edges and their corresponding minimum distances:" << endl;
//    for(int i = 2; i <= node; i++)
//    {
//        cout << par[i] << " - " << i << " : " << cost[i] << endl;
//    }
//    cout << "The total minimum distance: " << mst << endl;
//}
//
//int main()
//{
//    cin >> node >> edge;
//
//    for(int i = 0; i < edge; i++)
//    {
//        int x, y, w;
//        cin >> x >> y >> w;
//
//        graph[x].push_back(make_pair(y, w));
//        //graph[y].push_back(make_pair(x, w));
//    }
//
//    for(int i = 1; i <= node; i++)
//    {
//        cout << "For node " << i << ": ";
//        for(int j = 0; j < graph[i].size(); j++)
//        {
//            cout << "(" << graph[i][j].first << "," << graph[i][j].second << " )";
//        }
//        cout << endl;
//    }
//
//    Prims(1);
//}
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>g[100];
int vis[100],cost[100],par[100];
int n,e;
#define inf     10000
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
int tc;
void Prims(int sc)
{
    pq.push(make_pair(0,sc));
    for(int i=1; i<=n; i++)cost[i]=inf;
    while(!pq.empty())
    {
        int u=pq.top().second;
        int c=pq.top().first;
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        tc+=c;
        for(auto x:g[u])
        {
            if(cost[x.first]>x.second)
            {
                cost[x.first]=x.second;
                par[x.first]=u;
                pq.push(make_pair(cost[x.first],x.first));
            }
        }

    }
}
int main()
{
    cin>>n>>e;
    for(int i=0; i<e; i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        g[x].push_back(make_pair(y,w));
    }
    for(int i=1; i<=n; i++)
    {
        cout<<i<<"->";
        for(auto x:g[i])
        {
            cout<<"("<<x.first<<", "<<x.second<<")";
        }
        cout<<endl;
    }
    Prims(1);
    for(int i=2; i<=n; i++)
    {
        cout<<par[i]<<" -> "<<i<<"    =    "<<cost[i]<<endl;
    }
    cout<<"Total cost = "<<tc<<endl;
}

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


 The overall time complexity of the code is O(N * log N + edge),
  where "N" is the number of nodes, and "edge" is the number of edges.

  he priority queue operations (push, top, and pop) take O(log N) time,
   where "N" is the number of nodes.
*/

