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
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    long idx=0;
    long N;
    cin >> N;
    string s;
    map<string, long> s_map;
    ll count = 0;
    for(size_t i=0;i<N; i++)
    {
        cin >> s;
        sort(s.begin(), s.end());
        count += s_map[s];
        s_map[s]++;
    }
#ifdef TEST
    for(const auto& _s:s_map)
    {
        cerr << _s.first << ":" << _s.second << endl;
    }
#endif
    cout << count << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}