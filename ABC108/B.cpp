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
    long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll x = (x2-x1);
    ll y = (y2-y1);
    ll x3,y3, x4, y4;
    if(abs(x) >= abs(y))
    {
        if(x > 0)
        {
            cerr << "1" << endl;
            x3 = x2 - y;
            y3 = y2 + x;
            x4 = x3 - x;
            y4 = y3 - y;
        }
        else
        {
            cerr << "2" << endl;
            x3 = x2 - y;
            y3 = y2 + x;
            x4 = x3 - x;
            y4 = y3 - y;
        }
    }
    else
    {
        if(y > 0)
        {
            cerr << "3" << endl;
            x3 = x2 - y;
            y3 = y2 + x;
            x4 = x3 - x;
            y4 = y3 - y;
        }
        else
        {
            cerr << "4" << endl;
            x3 = x2 - y;
            y3 = y2 + x;
            x4 = x3 - x;
            y4 = y3 - y;
        }
    }
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}