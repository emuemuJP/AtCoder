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
    long N,T;
    cin >> N >> T;
    vector<ll> c(N);
    vector<ll> t(N);
    ll min_cost = INF;
    for(size_t i=0;i<N; i++)
    {
        cin >> c[i] >> t[i];
        if(t[i]<=T)
        {
            min_cost = min(min_cost, c[i]);
        }
    }
    if(min_cost!=INF) cout << min_cost << endl;
    else cout << "TLE" << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}