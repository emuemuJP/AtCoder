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
    vector<pair<long, long>> pos(N);
    for(size_t i=0;i<N; i++)
    {
        long x,y;
        cin >> x >> y;
        pos[i]=make_pair(x, y);
    }
    bool ok=false;
    for(size_t i=0;i<N; i++){
    for(size_t j=i+1;j<N; j++){
    for(size_t k=j+1;k<N; k++){
        ll x1 = pos[i].first;
        ll y1 = pos[i].second;
        ll x2 = pos[j].first;
        ll y2 = pos[j].second;
        ll x3 = pos[k].first;
        ll y3 = pos[k].second;
        x1 -= x3;
        x2 -= x3;
        y1 -= y3;
        y2 -= y3;
        if(x1 * y2 == x2 * y1)
        {
            cerr << i << ":" << j << ":" << k << endl;
            ok=true;
        }
    if(ok) break;}
    if(ok) break;}
    if(ok) break;}
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}