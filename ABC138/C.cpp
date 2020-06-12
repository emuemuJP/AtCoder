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
    ll N;
    cin >> N;
    vector<ll> v(N);
    for(size_t i=0;i<N; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    double value = v[0];
    for(size_t i=1;i<N; i++)
    {
        value = 1.0 * (value + v[i])/ 2.0;
    }
    cout << fixed << setprecision(10) << value << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}