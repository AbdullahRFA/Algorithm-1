//#include<bits/stdc++.h>
//using namespace std;
//vector<int> adj[100];
//vector<int> rev_adj[100];
//bool visited[100];
//stack<int> order;
//
//void dfs1(int node) {
//    visited[node] = true;
//    for (int neighbor : adj[node]) {
//        if (!visited[neighbor]) {
//            dfs1(neighbor);
//        }
//    }
//    order.push(node);
//}
//
//void dfs2(int node, vector<int>& component) {
//    visited[node] = true;
//    component.push_back(node);
//    for (int neighbor : rev_adj[node]) {
//        if (!visited[neighbor]) {
//            dfs2(neighbor, component);
//        }
//    }
//}
//
//int main() {
//    int n, e;
//    cin >> n >> e;
//
//    for (int i = 1; i <= n; i++) {
//        adj[i].clear();
//        rev_adj[i].clear();
//        visited[i] = false;
//    }
//    for (int i = 0; i < e; i++) {
//        int x, y;
//        cin >> x >> y;
//        adj[x].push_back(y);
//        rev_adj[y].push_back(x);
//    }
//
//    for (int i = 1; i <= n; i++) {
//        if (!visited[i]) {
//            dfs1(i);
//        }
//    }
//
//    for (int i = 1; i <= n; i++) {
//        visited[i] = false;
//    }
//
//    int c=0;
//            vector<int> component[100];
//    while (!order.empty()) {
//        int node = order.top();
//        order.pop();
//        if (!visited[node]) {
//            dfs2(node, component[c++]);
//
//        }
//    }
//        cout<<"Number of Strongly connected component is = "<<c<<endl;
//    cout << "Strongly Connected Components  are  :" << endl;
//    for(int i=0;i<c;i++)
//    {
//         for (int item : component[i]) {
//                cout << item << " ";
//            }
//            cout << endl;
//    }
//
//    return 0;
//}
#include<bits/stdc++.h>
using namespace std;
vector<int>g[100];
vector<int>adj_g[100];
int vis[100];
stack<int>order;
void dfs(int n)
{
    vis[n]=1;
    for(auto x:g[n])
        if(!vis[x])dfs(x);
    order.push(n);
}
void dfs1(int n,vector<int>&v)
{
    vis[n]=1;
    for(auto x:adj_g[n])if(!vis[x])dfs1(x,v);
    v.push_back(n);
}
int main()
{
    int n,e;
    cin>>n>>e;

    for(int i=0; i<e; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        adj_g[y].push_back(x);
    }
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    for(int i=0; i<100; i++)vis[i]=0;

        vector<int>tem[100];
        int c=0;
    while(!order.empty())
    {
        int p=order.top();
        order.pop();
        if(!vis[p])
        {
            dfs1(p,tem[c++]);


        }

    }
    cout<<"Number of connected component is = "<<c<<endl;
    for(int i=0;i<c;i++)
    {
     for(auto x: tem[i])cout<<x<<" ";
            cout<<endl;

    }
}

/*
8 14
1 2
2 5
2 6
2 3
3 7
3 4
4 3
4 8
5 1
5 6
6 7
7 6
7 8
8 8
Strongly Connected Components:
1 5 2
3 4
6 7
8

10 16
1 2
1 6
2 7
2 3
3 4
3 8
4 5
4 10
4 9
4 8
5 10
6 7
7 1
8 3
9 10
10 5
Strongly Connected Components:
1 7 2 6
3 8 4
9
5 10


Overall, the time complexity of this code is dominated
by the DFS traversal of the original graph and is O(N + E),
where N is the number of vertices, and E is the number of edges.

*/

