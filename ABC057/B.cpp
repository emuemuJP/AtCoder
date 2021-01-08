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
    long N,M;
    cin >> N >> M;
    vector<pair<ll,ll>> p(N);
    for(size_t i=0;i<N; i++)
    {
        ll a, b;
        cin >> a >> b;
        p[i] = make_pair(a, b);
    }
    vector<pair<ll,ll>> cp(N);
    for(size_t i=0;i<M; i++)
    {
        ll c, d;
        cin >> c >> d;
        cp[i] = make_pair(c, d);
    }
    for(size_t i=0;i<N; i++)
    {
        long idx = -1;
        ll dist = INF;
        for(size_t j=0;j<M; j++)
        {
            ll d = abs(cp[j].first - p[i].first) + abs(cp[j].second - p[i].second);
            if(d < dist)
            {
                dist = d;
                idx = j;
            }
        }
        cout << idx + 1 << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}