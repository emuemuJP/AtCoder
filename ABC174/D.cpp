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
    string c;
    cin >> c;
    ll w_count=0, r_count=0;
    for(size_t i=0;i<N; i++)
    {
        if(c[i]=='R') r_count++;
        else w_count++;
    }
    //cerr << r_count << ":" << w_count << endl;
    ll need_to_change_to_red = 0;
    for(size_t i=0;i<r_count; i++)
    {
        if(c[i]=='W') need_to_change_to_red++;
    }
    ll need_to_change_to_white = 0;
    for(size_t i=N-w_count;i<N; i++)
    {
        if(c[i]=='R') need_to_change_to_white++;
    }
    cout << max(need_to_change_to_white, need_to_change_to_red) << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}