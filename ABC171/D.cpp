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
    map<ll, ll> A;
    ll a;
    ll total_a=0;
    for(size_t i=0;i<N; i++)
    {
        cin >> a;
        A[a]++;
        total_a += a;
    }
    //for(auto i : A) cerr << i.first << ":" << i.second << endl;
    //cerr << total_a << endl;
    ll Q;
    cin >> Q;
    ll B, C;
    ll ans[Q];
    for(size_t i=0;i<Q; i++)
    {
        cin >> B >> C;
        ll num = A[B];
        A.erase(B);
        total_a = total_a - B*num + C*num;
        ans[i] = total_a;
        A[C] += num;
        //cerr << num << ":" << num << endl;
    }

    for(size_t i=0;i<Q; i++)
    {
        cout << ans[i] << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}