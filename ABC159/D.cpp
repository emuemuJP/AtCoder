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

ll combination(ll n, ll r) {
  if ( r * 2 > n ) r = n - r;
  ll dividend = 1;
  ll divisor  = 1;
  for (ll i = 1; i <= r; ++i ) {
    dividend *= (n-i+1);
    divisor  *= i;
  }
  return dividend / divisor;
}
//#define TEST
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    long idx=0;
    long N;
    cin >> N;
    map<long,long> A;
    vector<long> a(N);
    for(size_t i=0;i<N; i++)
    {
        cin >> a[i];
        A[a[i]]++;
    }

    ll total_counter = 0;
    long comb;
    for(auto itr = A.begin(); itr != A.end(); ++itr) {
        if(itr->second < 2)
        {
            comb = 0;
        }
        else
        {
            comb = combination(itr->second, 2);
        }
        total_counter += comb;
    }
    for(size_t i=0;i<a.size(); i++)
    {
        cout << total_counter - (A[a[i]] - 1) << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}