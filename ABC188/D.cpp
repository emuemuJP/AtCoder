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
    ll N, C;
    cin >> N >> C;
    vector<ll> a(N),b(N),c(N);
    vector<pair<ll, ll>> schedule;
    for(size_t i=0;i<N; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        /*
        for(size_t d=a[i];d<=b[i]; d++)
        {
            schedule[d] += c[i];
        }
        */
       schedule.emplace_back(a[i] - 1, c[i]);
       schedule.emplace_back(b[i], -c[i]);
    }
    ll total = 0, fee = 0, t = 0;
    sort(schedule.begin(), schedule.end());
    for(auto d: schedule)
    {
        //cerr << d.first << ":" << d.second << endl;
        if(d.first!= t)
        {
            total += min(C, fee) * (d.first - t);
            t = d.first;
        }
        fee += d.second;
    }
    /*
    for(auto d:schedule)
    {
        //cerr << d.first << endl;
        total+=min(d.second, C);
    }
    */
    cout << total << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}