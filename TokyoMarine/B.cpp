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
    ll A,B,V,W,T;
    cin >> A >> V;
    cin >> B >> W;
    cin >> T;
    ll dist = abs(B - A);
    ll diff = V-W;
    cerr << dist << ":" << diff << endl;
    if(diff <= 0)
    {
        cout << "NO" << endl;
        return 0;
    }

    double time = 1.0* dist / diff;
    if(time <= T) cout << "YES" << endl;
    else cout << "NO" << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}