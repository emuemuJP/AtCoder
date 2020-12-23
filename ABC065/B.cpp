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
    vector<long> a(N);
    for(size_t i=0;i<N; i++)
    {
        cin >> a[i];
    }
    vector<bool> a_ok(N, true);
    ll idx=0;
    ll count=0;
    while(a_ok[idx])
    {
        a_ok[idx]=false;
        count++;
        cerr << a[idx] << endl;
        idx=a[idx]-1;
        if(idx==1) break;
    }
    if(idx==1) cout << count << endl;
    else cout << -1 << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}