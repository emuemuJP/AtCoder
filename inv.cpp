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

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    long idx=0;

    ll a = 12345678900000;
    ll b = 100000;

    // a を 10000000007 で割ってから b の逆元をかけて計算
    cout << a % DIV * modinv(b, DIV) % DIV << endl;
    return 0;
}