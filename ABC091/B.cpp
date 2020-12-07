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
    map<string, int> key;
    map<string, int> s;
    for(size_t i=0;i<N; i++)
    {
        string tmp;
        cin >> tmp;
        s[tmp]++;
        key[tmp]++;
    }
    long M;
    cin >> M;
    map<string, int> t;
    for(size_t i=0;i<M; i++)
    {
        string tmp;
        cin >> tmp;
        t[tmp]++;
        key[tmp]++;
    }
    int max_money = 0;
    for(auto k: key)
    {
        max_money = max(s[k.first] - t[k.first], max_money);
    }
    cout << max_money << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}