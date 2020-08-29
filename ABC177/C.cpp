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
    vector<ll> sum(N);
    for(size_t i=0;i<N; i++)
    {
        cin >> A[i];
    }
    for(ll i=N-2;i>=0;i--)
    {
        sum[i] = (sum[i+1] + A[i+1]) % DIV;
        //cerr << sum[i] << endl;
    }

    ll total = 0;
    for(size_t i=0;i<N-1; i++)
    {
        //sum -= A[i];
        total += (A[i] * sum[i]) %DIV;
        total %= DIV;
        /*
        for(size_t j=i+1;j<N; j++)
        {
            ll mul = (A[i]*A[j]) % DIV;
            sum += mul;
            sum %= DIV;
        }
        */
    }
    cout << total << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}