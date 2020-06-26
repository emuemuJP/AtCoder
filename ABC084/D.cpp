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

bool isPrime(ll x){
    if(x < 2)return false;
    else if(x == 2) return true;
    if(x%2 == 0) return false;
    for(ll i = 3; i*i <= x; i += 2) if(x%i == 0) return false;
    return true;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    long Q;
    cin >> Q;
    vector<ll> odd2017(100001);
    vector<ll> _odd2017;
    for(size_t i=1;i<100001; i++)
    {
        if(isPrime(i))
        {
            if(i*2>=100001) continue;
            if(isPrime(i*2 - 1))
            {
                //cerr << i << ":" << i*2-1 << endl;
                _odd2017.push_back(i*2-1);
            }
        }
    }
    //for(auto i:_odd2017) cerr << i << endl;
    ll idx=0;
    for(size_t i=1;i<100001; i++)
    {
        if(i == _odd2017[idx])
        {
            odd2017[i]=odd2017[i-1]+1;
            idx++;
        }
        else odd2017[i]=odd2017[i-1];
        //cerr << i << ":" << odd2017[i] << endl;
    }

    vector<ll> l(Q), r(Q);
    for(size_t i=0;i<Q; i++)
    {
        cin >> l[i] >> r[i];
        //cerr << odd2017[r] << ":" << odd2017[l-1] << endl;
    }
    for(size_t i=0;i<Q;  i++)
    {
        cout << odd2017[r[i]] - odd2017[l[i]-1] << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}