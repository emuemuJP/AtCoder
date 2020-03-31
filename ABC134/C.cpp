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
//#define TEST
bool compare_by_pair(pair<long,long> a, pair<long,long> b) {
    if(a.second !=  b.second){
        return a.second < b.second;
    }
    return a.second == b.second;
}

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
    vector<pair<long, long>> A(N);
    long a;
    pair<long, long> best = make_pair(0, 0);
    long second_best=0;
    for(size_t i=0;i<N; i++)
    {
        cin >> a;
        if(a >= best.second)
        {
            second_best = best.second;
            best = make_pair(i, a);
        }
        else if(a > second_best) second_best = a;
    }
    for(size_t i=0;i<N; i++)
    {
        if(i != best.first) cout << best.second << endl;
        else cout << second_best << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}