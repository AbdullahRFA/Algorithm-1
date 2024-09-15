#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >graph[10];
int dis[100];
int par[100];
#define inf 1000
int node,edge;
int cost[100];
priority_queue< pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>>PQ;
void Dijkstra(int src)
{
    for(int i=1;i<=node;i++)cost[i]=inf;
    cost[src]=0;

    PQ.push(make_pair(0,src ));
    while(!PQ.empty())
    {
        int u = PQ.top().second;
        PQ.pop();
        for(int i=0;i<graph[u].size();i++)
        {
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if(cost[v] > cost[u] + w )
            {
                cost [v] = cost[u] + w;
                par[v] = u;
                PQ.push( make_pair(cost[u] + w, v));
            }

        }

    }

    for(int i=1;i<=5;i++)cout<<i<<" "<<cost[i]<<" "<<par[i]<<endl;
}

int main()
{

    cin>>node>>edge;

    for(int i=0;i<edge;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;

        graph[x].push_back(make_pair(y,w) );
        graph[y].push_back(make_pair(x,w) );
    }

/// Adjacency List Print
    for(int i=1;i<=node;i++)
    {
        cout<<"For node "<<i<<": ";
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<"("<<graph[i][j].first<<","<<graph[i][j].second<<" )";
        }
        cout<<endl;
    }

    Dijkstra(1);


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


 The overall time complexity of the code is O(N * (log N + edge)),
 where "N" is the number of nodes, and "edge" is the number of edges.
 The logarithmic factor comes from the priority queue operations inside Dijkstra's algorithm.
*/
