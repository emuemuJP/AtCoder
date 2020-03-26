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
    ll L, R;
    cin >> L >> R;
    const long div = 2019;
    // 2019の倍数が間にあれば0になる
    if(R / div - L / div > 0) cout << 0 << endl;
    // かけると2019の倍数になるかもしれない
    // 2019を超える可能性があるかどうかの判定
    else
    {
        ll _min = INF;
        for(size_t i=L%div;i<R%div; i++)
        {
            for(size_t j=(L+1)%div;j<=R%div; j++)
            {
                _min = min(_min, (ll)(i*j)%div);
            }
        }
        cout << _min << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}