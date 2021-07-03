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

std::vector<std::vector<ll>> dp(100001, vector<ll>(3, 0));

template<class T> bool chmax(T& a, const T b){
    bool isMax = false;
    if(a < b){
        a=b;
        isMax = true;
    }
    return isMax;
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
    vector<ll> a(N), b(N), c(N);
    for(size_t i=0;i<N; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    for(size_t i=1;i<=N; i++)
    {
        dp[i][0] = max(dp[i-1][1] + a[i-1], dp[i-1][2] + a[i-1]);
        dp[i][1] = max(dp[i-1][0] + b[i-1], dp[i-1][2] + b[i-1]);
        dp[i][2] = max(dp[i-1][0] + c[i-1], dp[i-1][1] + c[i-1]);
    }
    cout << max(dp[N][0], max(dp[N][1],dp[N][2])) << endl;


#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}