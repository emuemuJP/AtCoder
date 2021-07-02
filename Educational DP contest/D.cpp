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
    long N, W;
    cin >> N >> W;
    vector<ll> weight(N), value(N);
    for(size_t i=0;i<N; i++)
    {
        cin >> weight[i] >> value[i];
    }
    std::vector<std::vector<ll>> dp(N+1, vector<ll>(W+1, 0));
    for(size_t i=0;i<N; i++)
    {
        for(int w=0;w<=W; w++)
        {
            //選べる
            if(w - weight[i] >=0)
            {
                //cerr << i << ":" << w << endl;
                chmax(dp[i+1][w], dp[i][w-weight[i]]+value[i]);
            }
            //選ばない
            chmax(dp[i+1][w], dp[i][w]);
        }
    }

    cout << dp[N][W] << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}