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
    vector<string> W(N);
    bool ok = true;
    map<string, int> count;
    for(size_t i=0;i<N; i++)
    {
        cin >> W[i];
        count[W[i]]++;
        if(i>0 && W[i][0] != W[i-1][W[i-1].size()-1]) ok = false;
    }
    for(auto w: count) if(w.second > 1) ok=false;
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;

#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}