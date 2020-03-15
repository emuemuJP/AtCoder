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
  for (int i = 0; i < r; i++) {
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
    long idx=0;
  	long long n, a, b;
  	cin >> n >> a >> b;
  	ll ans = PowMod(2, n) - 1;
  	ll diff = (comb(n, a) + comb(n, b)) % DIV;
  	cout << (ans - diff + DIV) % DIV << endl;
  	return 0;
}