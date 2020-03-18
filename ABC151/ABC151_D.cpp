#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <stack>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;
using ll = long long;
const long long INF = (long long)1e18+1;
#define DIV 1000000007

struct Corr {
    int x;
    int y;
    int depth;
};
queue<Corr> q;
int32_t bfs(vector<vector<string>> grid) {
    // 既に探索の場所を1，探索していなかったら0を格納する配列
    vector<vector<bool>> ispassed(grid.size(), vector<bool>(grid[0].size(), false));
    // このような記述をしておくと，この後のfor文が綺麗にかける
    int dx[8] = {1, 0, -1, 0};
    int dy[8] = {0, 1, 0, -1};
    int depth = 0;
    while(!q.empty()) {
        Corr now = q.front();q.pop();
        ispassed[now.y][now.x] = true;
        for(int i = 0; i < 4; i++) {
            int nextx = now.x + dx[i];
            int nexty = now.y + dy[i];
            //cerr << nextx << "," << nexty << endl;
            // 探索する場所が配列外の場合
            if(nextx < 0 || nextx >= grid[0].size() || nexty < 0 || nexty >= grid.size()) continue;
            // 次に探索する場所のX座標がはみ出した時
            if(nextx >= grid[0].size() || grid[nexty][nextx] == "#") continue;
            if(nextx < 0 || grid[nexty][nextx] == "#") continue;
            // 次に探索する場所のY座標がはみ出した時
            if(nexty >= grid.size() || grid[nexty][nextx] == "#") continue;
            if(nexty < 0 || grid[nexty][nextx] == "#") continue;
            // 次に探索する場所が既に探索済みの場合
            if(ispassed[nexty][nextx]) continue;
            ispassed[nexty][nextx] = true;
            Corr next = {nextx, nexty, now.depth+1};
            depth = max(depth, next.depth);
            q.push(next);
        }
    }
    return depth;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    long idx=0;
    long H, W;
    cin >> H >> W;
    std::vector<std::vector<string>> mat(H, vector<string>(W, ""));
    for(size_t i=0;i<H; i++)
    {
        string line;
        cin >> line;
        for(size_t j=0;j<W; j++)
        {
            mat[i][j] = line[j];
        }
    }
    int max_distance = 0;

    for(size_t i=0;i<H; i++)
    {
        for(size_t j=0;j<W; j++)
        {
            int cost = 0;
            if(mat[i][j] == ".")
            {
                Corr start = {(int)j, (int)i, 0};
                q.push(start);
                cost = bfs(mat);
            }
            max_distance = max(max_distance, cost);
        }
    }
    cout << max_distance << endl;
    return 0;
}