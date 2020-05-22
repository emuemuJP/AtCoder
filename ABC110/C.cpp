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
    string S, T;
    cin >> S;
    cin >> T;
    map<char, ll> S_map;
    map<char, ll> T_map;
    for(size_t i=0;i<S.size(); i++)
    {
        S_map[S[i]]++;
        T_map[T[i]]++;
    }

    //for(auto m : S_map) cerr << m.first << ":" << m.second << " "; cerr << endl;
    //for(auto m : T_map) cerr << m.first << ":" << m.second << " "; cerr << endl;

    map<ll, vector<char>> diff_S;
    map<ll, vector<char>> diff_T;
    for(auto m : S_map)
    {
        if(m.second != T_map[m.first]) diff_S[m.second].push_back(m.first);
    }
    for(auto m : T_map)
    {
        if(m.second != S_map[m.first]) diff_T[m.second].push_back(m.first);
    }
    bool ok = true;
    for(auto m: diff_S)
    {
        if(m.second.size() != diff_T[m.first].size()) ok = false;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}