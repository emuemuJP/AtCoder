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
    long N;
    cin >> N;
    vector<ll> x(N);
    vector<ll> y(N);
    vector<ll> h(N);
    for(size_t i=0;i<N; i++)
    {
        cin >> x[i] >> y[i] >> h[i];
    }
    ll H = -1, Cx, Cy;
    //h = max(H - |x - Cx| - | y - Cy |, 0)
    // H は h 以上
    // Hは一意に定まる
    bool isOK;
    for(size_t cx=0;cx<=100; cx++)
    {
        for(size_t cy=0;cy<=100; cy++)
        {
            H = -1;
            isOK = true;
            for(size_t i=0;i<N; i++)
            {
                ll _H;
                if(h[i] == 0) continue;
                _H = h[i] + abs(ll(x[i] - cx)) + abs(ll(y[i] - cy));
                if(H==-1) H = max(_H, 0ll);
                else
                {
                    if(H != _H)
                    {
                        isOK = false;
                        break;
                    }
                }
            }
            for(size_t i=0;i<N; i++)
            {
                if(h[i]>0) continue;
                if(h[i] != max(H - abs(ll(x[i] - cx)) - abs(ll(y[i] - cy)), 0ll)) isOK = false;
            }
            if(isOK)
            {
                Cy = cy;
                break;
            }
        }
        if(isOK)
        {
            Cx = cx;
            break;
        }
    }
    cout << Cx << " " << Cy << " " << H << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}