#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 100000000
vector<pair<ll, ll>> g[101];
ll v, e;
void floydWarshall()
{
    vector<vector<ll>> dist(v, vector<ll>(v, inf));
    for (ll i = 0; i < v; i++)
    {
        dist[i][i] = 0;
        for (const pair<ll, ll>& edge : g[i])
        {
            ll j = edge.first;
            ll weight = edge.second;
            dist[i][j] = weight;
        }
    }

    for (ll k = 0; k < v; k++)
    {
        for (ll i = 0; i < v; i++)
        {
            for (ll j = 0; j < v; j++)
            {
                if (dist[i][k] != inf && dist[k][j] != inf)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    cout<<"Distance From Source '0' to every vertex : \n";
    cout<<"Vertex\tDistance From Source\n";
    for(ll i=0; i<v; i++)
    {
        cout<<i<<"\t\t"<<dist[0][i]<<endl;
    }
    cout<<endl;
    cout<<"Matrix form of shortest path : \n";
    for (ll i = 0; i < v; i++)
    {
        for (ll j = 0; j < v; j++)
        {
            if (dist[i][j] == inf)
                cout << "inf" << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "Enter the number of vertices and edges : ";
    cin >> v >> e;

    for (ll i = 0; i < e; i++)
    {
        ll x, y, c;
        cin >> x >> y >> c;
        g[x].push_back({y, c});
    }

    floydWarshall();

    return 0;
}
/*
Enter the number of vertices and edges : 5 8
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3

*/
