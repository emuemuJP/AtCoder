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
    ll N, H;
    cin >> N >> H;
    vector<ll> a(N);vector<ll> b(N);
    ll max_a = 0; ll max_a_index=0;
    ll max_a2 = 0; ll max_a2_index=0;
    for(size_t i=0;i<N; i++)
    {
        //aは何回でもできるがbは１回だけ
        cin >> a[i] >> b[i];
        if(a[i] > max_a)
        {
            max_a2 = max_a;max_a2_index=max_a_index;
            max_a = a[i];max_a_index=i;
        }
    }
    sort(b.rbegin(), b.rend());
    ll count = 0;
    for(ll i=0;i<N; i++)
    {
        if(/*(i != max_a_index || i != max_a2_index) &&*/ b[i] > max_a)
        {
            H -= b[i];
            count++;
        }
        if(H <= 0){cout << count << endl;return 0;}
    }

    ll a_count;
    /*
    if(max_a < b[max_a_index])
    {
        a_count = (H - b[max_a_index]) / max_a;
        if((H - b[max_a_index]) % max_a > 0) a_count++;
        cout << a_count + count + 1 << endl;
    }else
    {
        a_count = H / max_a;
        if(H % max_a > 0) a_count++;
        cout << a_count + count << endl;
    }
    */
    a_count = H / max_a;
    if(H % max_a > 0) a_count++;
    cout << a_count + count << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}