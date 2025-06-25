#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <tuple>
#include <algorithm>

using namespace std;

int H = 5, W = 5;
vector<string> M = {
    "S....",
    ".###.",
    ".#...",
    ".###.",
    "...#G"};

int id(int x, int y) { return x * W + y; }
pair<int, int> xy(int i) { return make_pair(i / W, i % W); }
double h(int a, int b)
{
    auto x1y1 = xy(a), x2y2 = xy(b);
    return hypot(x1y1.first - x2y2.first, x1y1.second - x2y2.second);
}

int main()
{
    int s = -1, g = -1, N = H * W;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
        {
            if (M[i][j] == 'S')
                s = id(i, j);
            if (M[i][j] == 'G')
                g = id(i, j);
        }

    vector<double> D(N, 1e9);
    vector<int> P(N, -1);
    typedef tuple<double, int> T;
    priority_queue<T, vector<T>, greater<T>> Q;
    D[s] = 0;
    Q.push(make_tuple(h(s, g), s));

    while (!Q.empty())
    {
        double f;
        int u;
        tie(f, u) = Q.top();
        Q.pop();
        if (u == g)
            break;
        int x = u / W, y = u % W;
        const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
        for (int d = 0; d < 4; ++d)
        {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= H || ny >= W || M[nx][ny] == '#')
                continue;
            int v = id(nx, ny);
            double ng = D[u] + 1;
            if (ng < D[v])
            {
                D[v] = ng;
                P[v] = u;
                Q.push(make_tuple(ng + h(v, g), v));
            }
        }
    }

    for (int v = g; v != -1; v = P[v])
    {
        int x = v / W, y = v % W;
        if (M[x][y] == '.')
            M[x][y] = '*';
    }
    for (auto &r : M)
        cout << r << '\n';
}