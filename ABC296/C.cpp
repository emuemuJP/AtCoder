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

//　あらかじめソートをすることで二分探索アルゴリズムを適用することができる問題
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
    vector<ll> A(N);
    for(size_t i=0;i<N; i++)
    {
        cin >> A[i];
    }
    bool yes = false;
    sort(A.begin(), A.end());
    for(size_t i=0;i<N; i++)
    {
        ll ans = A[i] - X;
        if (*(lower_bound(A.begin(), A.end(), ans)) == ans) yes = true;
    }
    if(yes) cout << "Yes" << endl;
    else cout << "No" << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}