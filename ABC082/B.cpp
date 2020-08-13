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
    string s, t;
    cin >> s >> t;
    map<char, ll> s_map;
    map<char, ll> t_map;
    map<string, ll> _map;
    for(size_t i=0;i<s.size(); i++)
    {
        s_map[s[i]]++;
        //_map[s[i]]++;
    }
    for(size_t i=0;i<t.size(); i++)
    {
        t_map[t[i]]++;
        //_map[t[i]]++;
    }
    string _s = "", _t = "";
    for (auto it = s_map.begin(), e = s_map.end(); it != e; ++it) {
        for(size_t i=0;i<it->second; i++)
        {
            _s += it->first;
        }
    }
    for (auto it = t_map.rbegin(), e = t_map.rend(); it != e; ++it) {
        for(size_t i=0;i<it->second; i++)
        {
            _t += it->first;
        }
    }
    _map[_s]++, _map[_t]++;
    bool ok = false;
    cerr << _s << ":" << _t << endl;
    for(auto i : _map)
    {
        cerr << i.first << endl;
        if(i.first == _s && i.first != _t) ok = true;
        break;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}