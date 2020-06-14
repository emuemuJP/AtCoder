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
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    ll X, N;
    cin >> X >> N;
    if(N!=0)
    {
        vector<ll> p(N+1);
        for(size_t i=0;i<N; i++)
        {
            cin >> p[i];
        }
        p[N]=102;
        sort(p.begin(), p.end());
        ll idx=0;
        ll minX = INF;
        ll min_i=0;
        for(ll i=0;i<=101; i++)
        {
            if(p[idx]==i)
            {
                idx++;
                continue;
            }
            //cerr << i << ":" << abs(i-X) << endl;
            if(abs(i-X) < minX)
            {
                minX= abs(i-X);
                min_i = i;
            }
        }
        cout << min_i << endl;
    }else cout << X << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}