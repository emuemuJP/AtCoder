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
    ll N, M;
    cin >> N >> M;
    //角は常に表
    ll corner_num = N>1&&M>1 ? 4: N==1&&M==1 ? 1:2;
    //bool corner = true;
    ll edge_row = N>1 ? 2*(M-2):(M-2);
    bool is_edge_row = N>1 ? true:false;
    ll edge_col = M>1 ? 2*(N-2):(N-2);
    bool is_edge_col = M>1 ? true:false;
    ll inside = (N>2 && M>2) ? N*M - (N*2 +M*2 -4):0;
    bool is_inside = false;
    if(corner_num > 1) cout << edge_row*!is_edge_row + edge_col*!is_edge_col + inside << endl;
    else cout << 1 << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}