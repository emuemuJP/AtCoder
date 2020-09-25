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
    long N, K;
    cin >> N >> K;
    vector<ll> h(N);
    for(size_t i=0;i<N; i++)
    {
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    ll min_dist=INF;
    for(int i=0;i<=N-K; i++)
    {
        ll dist=h[i+K-1]-h[i];
        min_dist=min(min_dist, dist);
    }
    cout << min_dist << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}