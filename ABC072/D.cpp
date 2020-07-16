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
    vector<ll> p(N);
    ll count = 0;
    bool sequential = false;
    ll next = 0;
    for(size_t i=0;i<N; i++)
    {
        cin >> p[i];
        if(p[i] == i+1) count++;
        if(i>0 && p[i] == i+1 && p[i-1] == i && !sequential)
        {
            next++;
            sequential = true;
        }else sequential = false;
    }
    cerr << count << ":" << next << endl;
    //隣り合っていたら１回で済むけど離れていたら２回必要
    cout << count - next << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}