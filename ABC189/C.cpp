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
    map<ll, int> key;
    for(size_t i=0;i<N; i++)
    {
        cin >> A[i];
        key[A[i]]++;
    }
    ll max_mikan = 0;
    for(auto k:key)
    {
        ll mikan = 0;
        for(size_t i=0;i<N; i++)
        {
            if(A[i] >= k.first) mikan+= k.first;
            else mikan = 0;
            max_mikan = max(max_mikan, mikan);
        }
    }
    cout << max_mikan << endl;

#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}