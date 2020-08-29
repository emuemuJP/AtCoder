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
    string S,T;
    cin >> S >> T;
    ll min_num = INF;
    for(size_t i=0;i<=S.size() - T.size(); i++)
    {
        string s = S.substr(i, T.size());
        cerr << s << endl;
        ll count = 0;
        for(size_t j=0;j<T.size(); j++)
        {
            if(s[j] == T[j]) count++;
        }
        min_num = min(min_num, ll(T.size() - count));
    }
    cout << min_num << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}