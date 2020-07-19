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

template <typename T>
inline T gcd(T a, T b) {return b ? gcd(b, a%b) : a;}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll nlcm(vector<ll> numbers) {
    ll res;
    res = numbers[0];
    for (ll i = 1; i < numbers.size(); i++) {
        res = lcm(res, numbers[i]);
    }
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
    long N;
    cin >> N;
    vector<ll> T(N);
    for(size_t i=0;i<N; i++)
    {
        cin >> T[i];
    }

    cout << nlcm(T) << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}