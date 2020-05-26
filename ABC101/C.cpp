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
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    ll N, K;
    cin >> N >> K;
    vector<ll> x(N+1);
    vector<ll> x_dist(N);
    ll cost = 0;
    ll total_cost = INF;
    ll sunuke = 0;
    ll sunuke_pos;
    for(size_t i=0;i<N; i++)
    {
        ll pos;
        cin >> pos;
        if(sunuke == 0 && pos >= 0)
        {
            sunuke++;
            x[i] = 0;
            sunuke_pos = i;
        }
        x[i+sunuke] = pos;
    }
    ll count = 0;

    for(size_t i=0;i<=N-K; i++)
    {
        cost = min(abs(x[i]) + abs(x[i+K] - x[i]), abs(x[i+K]) + abs(x[i+K] - x[i]));
        total_cost = min(total_cost, cost);
        //cerr << i << ":" << cost << endl;
        /*
        x_dist[i-1] = x[i] - x[i-1];
        count++;
        if(count <= K)
        {
            cost += x_dist[i-1];
            if(count == K) total_cost = min(total_cost, cost);
        }else
        {
            cost = cost + x_dist[i-1] - x_dist[i-1-K];
            total_cost = min(total_cost, cost);
        }
        */
    }
    cout << total_cost << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}