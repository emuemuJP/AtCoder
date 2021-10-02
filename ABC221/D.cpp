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
#include <set>
#include <unordered_map>
#include <chrono>
#include <numeric>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18+1;
const ll DIV = 1000000007;
//#define TEST
bool compare_by_pair(pair<ll,ll> a, pair<ll,ll> b) {
    if(a.first != b.first){
        return a.first < b.first;
    }
    return false;
}

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
    vector<pair<ll, ll>> AB(N);
    vector<ll> B(N);
    map<ll, ll> day;
    for(size_t i=0;i<N; i++)
    {
        ll a, b;
        cin >> a >> b;
        day[a]++;
        day[a+b]--;
        AB[i] = make_pair(a, b);
    }

    // sort(AB.begin(), AB.end(), compare_by_pair);
    vector<ll> num(N+1);
    // for(auto& ab:AB)
    // {
    //     cerr << ab.first << ":" << ab.second << endl;
    // }
    ll count = 0;
    ll prev_day = -1;
    for(auto &d:day)
    {
        if(prev_day==-1) prev_day=d.first-1;
        //cerr << count << ":" << d.first << ":" << d.second << endl;
        num[count] += d.first - prev_day;
        count+=d.second;
        prev_day = d.first;
    }
    for(size_t i=1;i<=N; i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}