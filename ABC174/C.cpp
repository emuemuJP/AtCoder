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

vector<ll> all_divs(ll n){
    vector<ll> ret;
    for(ll i = 1 ; i*i <= n ; ++i){
        if(n%i == 0){
            ret.push_back(i);
            if(i*i != n){
                ret.push_back(n/i);
            }
        }
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    long K;
    cin >> K;
    ll count=0;
    ll seven = 7;
    ll a[1000001];
    // 下一桁: 1 3 7 9
    // 鳩ノ巣原理：n, mを自然数とし、n > mとしたとき、
    // n 個のものを m 組にわけるとき少なくとも一つの組は２個以上のものを含む
    // ex.)5つの巣に72羽をいれるとき、15羽以上の鳩が入っている箱が少なくとも一つ存在する
    a[1]=7%K;
    for(size_t i=2;i<=K; i++)
    {
        a[i]=(a[i-1]*10+7)%K;
    }
    for(size_t i=1;i<=K; i++)
    {
        if(a[i]==0)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    /*
    while(true)
    {
        cerr << seven << endl;
        vector<ll> divs = all_divs(seven);
        for(auto i : divs) cerr << i << " ";
        cerr << endl;
        count++;
        seven = seven * 10 + 7;
        if(count==15) break;
    }
    */

#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}