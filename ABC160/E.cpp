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
const long long INF = (long long)1e18+1;
#define DIV 1000000007
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    long idx=0;
    long X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vector<ll> ans;

    vector<ll> p(A);
    for(size_t i=0;i<A; i++)
    {
        cin >> p[i];
    }
    sort(p.rbegin() ,p.rend());

    for(size_t i=0;i<X; i++)
    {
        ans.push_back(p[i]);
    }

    vector<ll> q(B);
    for(size_t i=0;i<B; i++)
    {
        cin >> q[i];
    }
    sort(q.rbegin() , q.rend());

    for(size_t i=0;i<Y; i++)
    {
        ans.push_back(q[i]);
    }

    ll r;
    for(size_t i=0;i<C; i++)
    {
        cin >> r;
        ans.push_back(r);
    }

    sort(ans.rbegin() , ans.rend());

    ll total = 0;
    for(size_t i=0;i<X+Y; i++)
    {
        total += ans[i];
    }
    cout << total << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}