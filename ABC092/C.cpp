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
    ll N;
    cin >> N;
    vector<ll> A(N+2);
    ll total_dist = 0;
    A[0] = 0;
    for(size_t i=1;i<=N; i++)
    {
        cin >> A[i];
        total_dist += abs(A[i] - A[i-1]);
    }
    A[N+1] = 0;
    total_dist += abs(A[N+1] - A[N]);
    /*
    for(size_t i=0;i<A.size(); i++)
    {
        cerr << A[i] << endl;
    }
    cerr << total_dist << endl;
    */
    for(size_t i=1;i<=N; i++)
    {
        ll dist = total_dist;
        dist -= abs(A[i] - A[i-1]);
        dist -= abs(A[i+1] - A[i]);
        dist += abs(A[i+1] - A[i-1]);
        cout << dist << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}