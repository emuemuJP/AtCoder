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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    ll min_num = INF;
    for(size_t i=0;i<N; i++)
    {
        cin >> A[i];
        min_num = min(min_num, A[i]);
    }
    vector<ll> min_index;
    for(size_t i=0;i<N; i++)
    {
        if(min_num == A[i]) min_index.push_back(i);
    }
    ll _idx = 0;
    ll dist=0;
    ll count = 0;
    if((N - min_index.size()) % (K-1) == 0) count = (N-min_index.size()) / (K-1);
    else count = (N-min_index.size()) / (K-1) + 1;
    cout << count << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}