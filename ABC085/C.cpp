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
    ll N, Y;
    cin >> N >> Y;
    ll max_x = Y / 10000;
    ll max_y = Y / 5000;
    ll max_z = Y / 1000;
    //cerr << max_x << ":" << max_y << ":" << max_z << endl;
    ll x, y, z;
    if(N < max_x || N > max_z)
    {
        cout << "-1 -1 -1" << endl;
        return 0;
    }
    bool found = false;
    for(x=max_x;x>=0; x--)
    {
        ll res = Y - 10000*x;
        ll resN = N - x;
        //cerr << resN << ":" << res/1000 << ":" << res/5000 << endl;
        max_y = res / 5000;
        if(res / 1000 < resN && res / 5000 > resN) continue;
        for(y=max_y;y>=0;y--)
        {
            ll res2 = res-5000*y;
            ll resN2 = resN - y;
            if(resN2 == res2 / 1000)
            {
                z = resN2;
                found=true;
                break;
            }
        }
        if(found) break;
    }
    if(!found) cout << "-1 -1 -1" << endl;
    else cout << x << " " << y << " " << z << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}