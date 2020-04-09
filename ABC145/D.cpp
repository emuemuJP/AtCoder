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


ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod) {
    return modpow(a, mod - 2, mod);
}

ll comb(ll n, ll r) {
  ll res, deno, mole;
  res = deno = mole = 1;
  for (ll i = 0; i < r; i++) {
    mole *= (n - i);
    mole %= DIV;
    deno *= (r - i);
    deno %= DIV;
  }
  res = modinv(deno, DIV);
  res = (res * mole) % DIV;
  return res;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    long idx=0;
    long X, Y;
    cin >> X >> Y;
    if(Y >= X / 2.0 && Y <= 2.0 * X && (X+Y) % 3 ==0)
    {
        long move_count = (X+Y)/3;
        // x軸への必要移動回数
        long x_move = (move_count * 2 - X);
        cout << comb(move_count, x_move) << endl;
    }
    else
        cout << 0 << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}