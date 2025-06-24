#include <iostream>
#include <vector>

using namespace std;

vector<int> dijkstra(const vector<vector<int>> &g, int s)
{
    int n = g.size(), INF = 1e9;
    vector<int> d(n, INF), vis(n);
    d[s] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1;
        for (int v = 0; v < n; v++)
            if (!vis[v] && (u == -1 || d[v] < d[u]))
                u = v;
        vis[u] = 1;
        for (int v = 0; v < n; v++)
            if (g[u][v] < INF)
                d[v] = min(d[v], d[u] + g[u][v]);
    }
    return d;
}

int main()
{
    int INF = 1e9;
    vector<vector<int>> g = {
        {0, 10, INF, INF, 5},
        {INF, 0, 1, INF, 2},
        {INF, INF, 0, 4, INF},
        {7, INF, 6, 0, INF},
        {INF, 3, 9, 2, 0}};
    vector<int> dist = dijkstra(g, 0);
    for (int i = 0; i < dist.size(); i++)
        cout << "dist[" << i << "] = " << (dist[i] == INF ? -1 : dist[i]) << "\n";
}
