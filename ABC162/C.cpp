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

template <typename T>
inline T gcd(T a, T b) {return b ? gcd(b, a%b) : a;}

ll ngcd(vector<ll> a){
    ll res;
    res = a[0];
    for(ll i = 1; i < a.size() && res != 1; i++) {
        res = gcd(a[i], res);
    }
    return res;
}
//#define TEST
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    long idx=0;
    long K;
    cin >> K;
    ll total = 0;
    for(size_t i=1;i<=K; i++)
    {
        for(size_t j=1;j<=K; j++)
        {
            for(size_t k=1;k<=K; k++)
            {
                vector<ll> num={(ll)i, (ll)j, (ll)k};
                total += ngcd(num);
            }
        }
    }
    cout << total << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}