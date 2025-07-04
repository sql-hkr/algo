#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int h = 5, w = 7, ans = 1e9;
vector<string> m = {
    "#######",
    "#S..#G#",
    "#.##..#",
    "#.....#",
    "#######"};
bool vis[5][7];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int d)
{
    if (m[x][y] == 'G')
    {
        ans = min(ans, d);
        return;
    }
    vis[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (m[nx][ny] != '#' && !vis[nx][ny])
            dfs(nx, ny, d + 1);
    }
    vis[x][y] = false;
}

int main()
{
    int sx, sy;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (m[i][j] == 'S')
                sx = i, sy = j;
    dfs(sx, sy, 0);
    cout << (ans == 1e9 ? -1 : ans) << endl;
}
