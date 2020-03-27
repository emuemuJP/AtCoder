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
    ll N, K, Q;
    cin >> N >> K >> Q;
    ll ans;
    vector<long> p(N, 0);
    for(size_t i=0;i<Q; i++)
    {
        cin >> ans;
        p[ans-1] ++;
    }
    //番号と保持ポイント
    for(size_t i=0;i<N; i++)
    {
        //cerr << i << "," << K  - (Q - p[i]) << endl;
        if(K  - (Q - p[i]) > 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}