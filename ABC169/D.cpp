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

map<ll, ll> prime_factorization(ll n){
    map<ll,ll> ret;
    for(ll i=2;i*i<n;i ++){
        while(n%i==0){
            ret[i] ++;
            n /= i;
        }
    }
    if(n!=1) ret[n]=1;
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
    ll N;
    cin >> N;
    map<ll,ll> divs = prime_factorization(N);
    ll count=0;
    ll Nmax = 1000000000000;
    ll max_e = 1;
    while(Nmax > pow(2, max_e)) max_e++;
    //cerr << max_e << endl;
    vector<ll> dcount = {1, 3, 6, 10, 15, 21, 28, 36, 45};
    for(auto i : divs)
    {
        //cerr << i.first << ":" << i.second << endl;
        //3: 1, 2
        //4: 1, 3
        //5: 1, 4
        //1  2  3   4   5   6   7,  8,  9
        //1, 3, 6, 10, 15, 21, 28, 36, 45
        for(ll d=0;d<dcount.size();d++)
        {
            if(i.second < dcount[d])
            {
                count+=d;
                break;
            }
        }
    }
    cout << count << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}