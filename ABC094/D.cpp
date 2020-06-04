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

ll comb(ll n, ll r) {
    ll res, deno, mole;
    res = deno = mole = 1;
    for (ll i = 0; i < r; i++) {
        mole *= (n - i);
        //mole %= DIV;
        deno *= (r - i);
        //deno %= DIV;
    }
    //res = modinv(deno, DIV);
    //res = (res / mole) % DIV;
    return mole / deno;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(size_t i=0;i<n; i++)
    {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    //for(size_t i=0;i<n; i++)
    //{
    //    cerr << a[i] << endl;
    //}

    ll max_comb = INF;
    pair<ll, ll> max_pair;
    double center = a[0] / 2.0;
    ll center_index = 1;
    for(size_t i=1;i<n; i++)
    {
        if(abs(center - a[i]) < max_comb)
        {
            //cerr << abs(center - a[i]) << ":" << a[i] << endl;
            max_comb = abs(center - a[i]);
            center_index = i;
        }
    }
    /*
    for(ll i=0;i<n-1; i++)
    {
        for(ll j=i+1;j<n; j++)
        {
            ll _comb = comb(a[i], a[j]);
            if(max_comb < _comb)
            {
                max_comb = _comb;
                max_pair = make_pair(a[i], a[j]);
            }
            //cerr << a[i] << ":" << a[j] << ":" << _comb << endl;
        }
    }
    */

    //cerr << max_comb << endl;
    cout << a[0] << " " << a[center_index] << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}