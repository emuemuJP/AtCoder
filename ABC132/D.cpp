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

ll PowMod(ll n, ll p) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    ll t = PowMod(n, p / 2);
    return t * t % DIV;
  }
  return n * PowMod(n, p - 1) % DIV;
}

ll comb(ll n, ll r) {
  // 分母と分子。いい名前思いつかなかった
  ll res, deno, mole;
  res = deno = mole = 1;
  for (ll i = 0; i < r; i++) {
    mole *= (n - i);
    mole %= DIV;
    deno *= (r - i);
    deno %= DIV;
  }
  // 分母の逆元
  res = PowMod(deno, DIV - 2);
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
    long N,K;
    cin >> N >> K;
    long red = N - K;

    for(size_t i=1;i<=K; i++)
    {
        if(min((long)K-i, (long)red-i+1) < 0) {
            cout << 0 << endl;
            continue;
        }
        // 赤いボールの間 red+1 箇所から青いボールのまとまり i を置く場所を考える comb(red+1 , red-i+1)
        // 青いボール、ボールとボールの間 K-1 個から i-1 個の場所を選択する方法　comb(K-1 , K-i)
        cout << comb(K-1 , K-i) * comb(red+1 , i) % DIV << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}