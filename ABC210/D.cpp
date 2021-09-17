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
    vector<vector<ll>> A(H, vector<ll>(W)), RD(H, vector<ll>(W, INF)), LD(H, vector<ll>(W, INF));
    for(auto& a : A) for(ll& i : a) cin >> i;
    //駅の位置関係が ＼ となる場合をサーチ
    for(ll i = 0; i < H; i++) for(ll j = 0; j < W; j++){
        //そこで駅を立てるのが安いか、そこに至るまででより安い建て方があるか？
        //どちらにせよ移動費はかかるのでCを足す
        const ll x = min(A[i][j], RD[i][j]) + C;
        //探索可能ならサーチ
        if(j + 1 < W) chmin(RD[i][j + 1], x);
        if(i + 1 < H) chmin(RD[i + 1][j], x);
    }
    //駅の位置関係が ／ となる場合をサーチ
    for(ll i = 0; i < H; i++) for(ll j = W; j--; ){
        const ll x = min(A[i][j], LD[i][j]) + C;
        if(j) chmin(LD[i][j - 1], x);
        if(i + 1 < H) chmin(LD[i + 1][j], x);
    }
    ll ans = INF;
    for(ll i = 0; i < H; i++) for(ll j = 0; j < W; j++)
    {
        chmin(ans, A[i][j] + min(RD[i][j], LD[i][j]));
        //cerr << RD[i][j] << ":" << LD[i][j] << endl;
    }
    cout << ans << endl;
    // std::vector<std::vector<ll>> A(H, vector<ll>(W, 0));
    // vector<ll> A_(H*W);
    // for(size_t i=0;i<H; i++)
    // {
    //     for(size_t j=0;j<W; j++)
    //     {
    //         cin >> A[i][j];
    //         A_[j + i*W] = A[i][j];
    //         //cerr << i*W + j << endl;
    //     }
    // }
    // ll cost = INF;
    // for(size_t i=0;i<H*W; i++)
    // {
    //     ll h_i = i / W;
    //     ll w_i = i % W;
    //     //cerr << A_[i] << endl;
    //     if(A_[i] > cost) continue;
    //     ll max_dist = (cost - A_[i]) / C;
    //     for(size_t j=i+1;j<H*W; j++)
    //     {
    //         ll h_j = j / W;
    //         ll w_j = j % W;
    //         ll dist = abs(h_j - h_i) + abs(w_j - w_i);
    //         if(dist > max_dist) continue;
    //         chmin(cost, A_[i] +  A_[j] + C * dist);
    //         //cerr << h_j << ":" << w_j << ":" << A_[j] << endl;
    //     }
    // }
    // cout << cost << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}