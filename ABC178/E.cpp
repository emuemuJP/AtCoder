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
    long N;
    cin >> N;
    vector<ll> x(N);
    vector<ll> y(N);
    vector<ll> p, m;
    for(size_t i=0;i<N; i++)
    {
        cin >> x[i] >> y[i];
        p.push_back(x[i]+y[i]);
        m.push_back(x[i]-y[i]);
    }
    sort(p.begin(), p.end());
    sort(m.begin(), m.end());
    cout << max(p[N-1] - p[0], m[N-1] - m[0]) << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}