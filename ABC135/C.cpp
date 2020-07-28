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
    vector<ll> A(N+1);
    vector<ll> B(N);
    ll a;
    for(size_t i=0;i<N+1; i++)
    {
        cin >> A[i];
    }
    for(size_t i=0;i<N; i++)
    {
        cin >> B[i];
    }
    ll count = 0;
    for(size_t i=0;i<N; i++)
    {
        count += min(A[i], B[i]);
        if(A[i] < B[i])
        {
            count+=min(A[i+1], B[i] - A[i]);
            A[i+1] -= min(A[i+1], B[i] - A[i]);
        }
    }
    cout << count << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}