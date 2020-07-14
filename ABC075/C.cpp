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

void dfs(const vector<vector<ll>> & graph, vector<bool>& visited, const ll start, ll node, const pair<ll,ll> pair)
{
    visited[node] = true;
    for(size_t i=0;i<graph[node].size(); i++)
    {
        if(visited[graph[node][i]]) continue;
        if((pair.first == node && pair.second == graph[node][i])
        || (pair.second == node && pair.first == graph[node][i])) continue;
        dfs(graph, visited, start, graph[node][i], pair);
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
    long N,M;
    cin >> N >> M;
    vector<vector<ll>> graph(N);
    long a, b;
    vector<pair<ll,ll>> edge(M);
    for(size_t i=0;i<M; i++)
    {
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
        edge[i] = make_pair(a-1, b-1);
    }
    ll count=0;
    for(size_t i=0;i<M; i++)
    {
        vector<bool> visited(N, false);
        dfs(graph, visited, 0, 0, edge[i]);
        for(auto i : visited) if(!i){count++;break;}
    }
    cout << count << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}