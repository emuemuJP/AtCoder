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
    std::vector<std::vector<bool>> F(N, vector<bool>(10, false));
    for(size_t i=0;i<N; i++)
    {
        bool run;
        for(size_t j=0;j<10; j++)
        {
            cin >> run;
            F[i][j] = run;
        }
    }
    std::vector<std::vector<ll>> P(N, vector<ll>(11, 0));
    for(size_t i=0;i<N; i++)
    {
        ll profit;
        for(size_t j=0;j<=10; j++)
        {
            cin >> profit;
            P[i][j] = profit;
        }
    }
    /*
    for(size_t i=0;i<N; i++)
    {
        for(size_t j=0;j<10; j++)
        {
            cerr << F[i][j] << " ";
        }
        cerr << endl;
    }
    for(size_t i=0;i<N; i++)
    {
        for(size_t j=0;j<=10; j++)
        {
            cerr << P[i][j] << " ";
        }
        cerr << endl;
    }
    */
    ll res = -INF;
    for(ll b=1;b<(1<<10); b++)
    {
        ll cc = 0;
        for(size_t i=0;i<N; i++)
        {
            ll c = 0;
            for(size_t j=0;j<10; j++)
            {
                if((b>>j & true) && F[i][j]) c++;
            }
            cc += P[i][c];
        }
        if(res < cc) res = cc;
    }
    cout << res << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}