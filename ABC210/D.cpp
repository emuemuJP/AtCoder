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

template<class T> bool chmin(T& a, const T b){
    bool isMin = false;
    if(a > b){
        a=b;
        isMin = true;
    }
    return isMin;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    ll H,W,C;
    cin >> H >> W >> C;
    std::vector<std::vector<ll>> A(H, vector<ll>(W, 0));
    vector<ll> B(H*W);
    for(size_t i=0;i<H; i++)
    {
        for(size_t j=0;j<W; j++)
        {
            cin >> A[i][j];
            cin >> B[i*W + j];
        }
    }
    ll cost = INF;
    for(size_t i=0;i<H*W; i++)
    {
        ll h_i = i / W;
        ll w_i = i % W;
        ll dist = (cost -  A[h_i][w_i]) / C;
        if((cost -  A[h_i][w_i]) % C >0) dist++;

        for(ll h_j=h_i;h_j<min(h_i+dist, H); h_j++)
        {
            ll dist_h = abs(h_j - h_i);
            for(ll w_j=max(w_i - (dist - dist_h), 0ll);w_j<max(min(w_i + (dist - dist_h), W), W); w_j++)
            {
                if(h_j==h_i && w_j <= w_i) continue;
                ll dist_w = abs(w_j - w_i);
                chmin(cost, A[h_i][w_i] + A[h_j][w_j]+C*(dist_h+dist_w));
            }
        }

    }
    cout << cost << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}