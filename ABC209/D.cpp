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
#include <set>
#include <unordered_map>
#include <chrono>
#include <numeric>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18+1;
const ll DIV = 1000000007;
//#define TEST

template<class T> bool chmin(T& a, const T b){
    bool isMin = false;
    if(a > b){
        a=b;
        isMin = true;
    }
    return isMin;
}

int cost;

void calc(const ll& start, ll now, const ll prev, const ll & dist, const vector<vector<ll>>& graph, int length)
{
    if(now == dist)
    {
        chmin(cost, length);
        return;
    }
    length++;
    for(size_t i=0;i<graph[now].size(); i++)
    {
        ll next = graph[now][i];
        if(next!=prev) calc(start, next, now, dist, graph, length);
    }
}

void search(const ll& start, ll now, const ll prev, const vector<vector<ll>>& graph, int length, vector<bool>& color)
{
    length++;
    color[now] = !color[prev];
    for(size_t i=0;i<graph[now].size(); i++)
    {
        ll next = graph[now][i];
        if(next!=prev) search(start, next, now, graph, length, color);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    ll N, Q;
    cin >> N >>Q;
    vector<vector<ll>> graph(N);
    ll a,b;
    for(size_t i=0;i<N-1; i++)
    {
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    //街間の距離がわかればどこで会うかわかる

    //  ある街間の距離を事前計算する？
    //      メモリ効率が悪く実行不可能
    //          std::vector<std::vector<int>> D(N, vector<int>(N, 100000));
    //      メモリ効率よく持つ方法を探す？
    //          街を偶数・奇数の場合で色塗りすることでその意味を持たせる
    //  道が少ないことを利用する？
    //      道が少ないためグラフがループ構造を持つことがない
    //      ある町に辿り着くための方法が１通りしかない
    vector<bool> color(N, false);
    search(0, 0, 0, graph, 0, color);

    ll c,d;
    for(size_t i=0;i<Q; i++)
    {
        cin >> c >> d;
        c-=1;
        d-=1;
        if(color[c] == color[d]) cout << "Town" << endl;
        else cout << "Road" << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}