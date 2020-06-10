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
#include <chrono>
#include <numeric>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18+1;
const ll DIV = 1000000007;
//#define TEST

struct Corr {
    int x;
    int y;
    ll depth;
};
queue<Corr> q;
ll bfs(vector<vector<char>> grid) {
    // 既に探索の場所を1，探索していなかったら0を格納する配列
    //cerr << grid.size() << ":" << grid[0].size() << endl;
    vector<vector<bool>> ispassed(grid.size(), vector<bool>(grid[0].size(), false));
    // このような記述をしておくと，この後のfor文が綺麗にかける
    ll minimum_cost = INF;
    int dx[8] = {1, 0, -1, 0};
    int dy[8] = {0, 1, 0, -1};
    while(!q.empty()) {
        Corr now = q.front();q.pop();
        //cerr << now.x << ":" << now.y << ":" << now.depth << endl;
        ispassed[now.y][now.x] = true;
        for(int i = 0; i < 4; i++) {
            int nextx = now.x + dx[i];
            int nexty = now.y + dy[i];
            // 探索する場所が配列外の場合
            if(nextx < 0 || nextx >= grid[0].size() || nexty < 0 || nexty >= grid.size()) continue;
            // 次に探索する場所が既に探索済みの場合
            if(ispassed[nexty][nextx]) continue;
            if(grid[nexty][nextx] == '#') continue;
            ispassed[nexty][nextx] = true;
            Corr next = {nextx, nexty, now.depth+1};
            if(nextx == grid[0].size()-1 && nexty == grid.size()-1) minimum_cost = min(ll(minimum_cost), next.depth);
            q.push(next);
        }
    }
    return minimum_cost;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    long H, W;
    cin >> H >> W;
    std::vector<std::vector<char>> mat(H, vector<char>(W, ' '));
    ll count_white = 0;
    for(size_t i=0;i<H; i++)
    {
        for(size_t j=0;j<W; j++)
        {
            cin >> mat[i][j];
            if(mat[i][j] == '.') count_white++;
        }
    }
    /*
    cerr << count_white << endl;
    for(size_t i=0;i<H; i++)
    {
        for(size_t j=0;j<W; j++)
        {
            cerr << mat[i][j] << " ";
        }
        cerr << endl;
    }
    */
    Corr i = Corr{0, 0, 1};
    q.push(i);
    ll minimum_cost = bfs(mat);
    if(minimum_cost == INF) cout << -1 << endl;
    else{
        //cerr << minimum_cost << endl;
        cout << count_white - minimum_cost << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}