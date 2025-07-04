#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int h = 5, w = 7, sx, sy, gx, gy;
    vector<string> m = {
        "#######",
        "#S..#G#",
        "#.##..#",
        "#.....#",
        "#######"};
    vector<vector<int>> d(h, vector<int>(w, -1));
    queue<pair<int, int>> q;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (m[i][j] == 'S')
                sx = i, sy = j;
    d[sx][sy] = 0;
    q.emplace(sx, sy);
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (m[nx][ny] != '#' && d[nx][ny] == -1)
                d[nx][ny] = d[x][y] + 1, q.emplace(nx, ny);
        }
    }
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (m[i][j] == 'G')
                gx = i, gy = j;
    cout << d[gx][gy] << endl;
}
