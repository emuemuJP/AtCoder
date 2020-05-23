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


template <typename T>
inline T gcd(T a, T b) {return b ? gcd(b, a%b) : a;}

ll ngcd(vector<ll> a){
    ll res;
    res = a[0];
    for(ll i = 1; i < a.size() && res != 1; i++) {
        res = gcd(a[i], res);
    }
    return res;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    ll N, X;
    cin >> N >> X;
    vector<ll> x(N+1);
    for(size_t i=0;i<N; i++)
    {
        cin >> x[i];
    }
    x[N] = X;
    sort(x.begin(), x.end());
    //for(auto i : x) cerr << i << endl;
    vector<ll> x_dist(N);
    for(size_t i=0;i<N; i++)
    {
        x_dist[i] = x[i+1] - x[i];
        //cerr << x_dist[i] << endl;
    }

    cout <<  ngcd(x_dist) << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}