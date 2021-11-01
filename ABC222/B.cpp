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
const ll INF = (ll)1e18 + 1;
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
    vector<ll> a(N), b(N);
    vector<vector<ll>> n(N);
    for (size_t i = 0; i < N-1; i++)
    {
        cin >> a[i] >> b[i];
        n[a[i]-1].push_back(b[i]-1);
        n[b[i]-1].push_back(a[i]-1);
    }
    bool star = false;
    for(size_t i=0;i<N; i++)
    {
        if(n[i].size() == N-1) star = true;
    }
    if(star) cout << "Yes" << endl;
    else cout << "No" <<endl;
#ifdef TES
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}