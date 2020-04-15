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
    vector<string> s(N);
    vector< map<char, long> > s_map(N);
    for(size_t i=0;i<N; i++)
    {
        cin >> s[i];
        for(size_t j=0;j<10; j++)
        {
            s_map[i][s[i][j]]++;
        }
    }
    ll count = 0;
    for(size_t i=0;i<N; i++)
    {
        for(size_t j=i+1;j<N; j++)
        {
            if(s_map[i] == s_map[j]) count++;
        }
    }
    cout << count << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}