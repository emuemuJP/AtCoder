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
    long N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    vector<ll> C(N);
    for(size_t i=0;i<N; i++) cin >> A[i];
    for(size_t i=0;i<N; i++) cin >> B[i];
    for(size_t i=0;i<N; i++) cin >> C[i];


    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    ll comb_count = 0;
    for(size_t j=0;j<N; j++)
    {
        auto A_it = upper_bound(A.begin(), A.end(), B[j]-1);
        size_t A_end = distance(A.begin(), A_it);
        auto C_it = lower_bound(C.begin(), C.end(), B[j]+1);
        size_t C_start = distance(C.begin(), C_it);
        comb_count += A_end * (C.size() - C_start);
    }
    cout << comb_count << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}