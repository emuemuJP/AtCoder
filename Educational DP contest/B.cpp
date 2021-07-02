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

vector<ll> dp(100000, INF);

template<class T> bool chmin(T& a, const T b){
    bool isMin = false;
    if(a > b){
        a=b;
        isMin = true;
    }
    return isMin;
}

ll rec(const vector<ll>& h, ll i, const ll K)
{
    if(dp[i] < INF) return dp[i];
    if(i == 0) return 0;
    ll res = INF;
    for(int k=1;k<=K; k++)
    {
        //cerr << i - k << ":" << i << ":" << k << endl;
        if(i-k >= 0) chmin(res, rec(h, i-k, K) + abs(h[i]- h[i-k]));
    }
    return dp[i] = res;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    ll N, K;
    cin >> N >> K;
    vector<ll> h(N);
    for(size_t i=0;i<N; i++)
    {
        cin >> h[i];
    }
    dp[0] = 0;
    cout << rec(h, N-1, K) << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}