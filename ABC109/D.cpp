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
    long H,W;
    cin >> H >> W;
    std::vector<std::vector<long>> a(H, vector<long>(W, 0));
    std::vector<std::vector<bool>> explore(H, vector<bool>(W, false));
    ll total = 0;
    for(size_t i=0;i<H; i++)
    {
        for(size_t j=0;j<W; j++)
        {
            cin >> a[i][j];
            total += a[i][j];
        }
    }
    //cerr << total << endl;
    ll ans=0;
    vector<long> x, y, x2, y2;
    for(size_t i=0;i<H-1; i++)
    {
        for(size_t j=0;j<W; j++)
        {
            if(a[i][j] % 2 == 1)
            {
                ans++;
                a[i+1][j]++;
                x.push_back(i+1);
                y.push_back(j+1);
                x2.push_back(i+2);
                y2.push_back(j+1);
            }
        }
    }

    for(size_t j=0;j<W-1; j++)
    {
        if(a[H-1][j] % 2 == 1)
        {
            ans++;
            a[H-1][j+1]++;
            x.push_back(H);
            y.push_back(j+1);
            x2.push_back(H);
            y2.push_back(j+2);
        }
    }

    cout << ans << endl;
    for(size_t i=0;i<ans; i++)
    {
        cout << x[i] << " " << y[i] << " " << x2[i] << " " << y2[i] << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}