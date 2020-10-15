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
    long N, M, X;
    cin >> N >> M >> X;
    vector<ll> A(N+1);
    for(size_t i=0;i<M; i++)
    {
        ll ind;
        cin >> ind;
        A[ind]++;
    }
    for(size_t i=0;i<N+1; i++)
    {
        cerr << A[i] << endl;
    }
    ll left=0;
    ll right=0;
    for(size_t i=0;i<X; i++)
    {
        left+=A[i];
    }
    for(size_t i=X;i<N+1; i++)
    {
        right+=A[i];
    }
    cout << min(left, right) << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}