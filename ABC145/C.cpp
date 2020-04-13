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
    vector<pair<long, long>> pos(N);
    long x,y;
    for(size_t i=0;i<N; i++)
    {
        cin >> x >> y;
        pos[i] = make_pair(x, y);
    }
    long count = 0;
    double total_distance;
    for(size_t i=0;i<N; i++)
    {
        for(size_t j=i+1;j<N; j++)
        {
            total_distance += sqrt(pow(pos[i].first-pos[j].first, 2) + pow(pos[i].second-pos[j].second, 2));
            count++;
        }
    }
    cerr << count << endl;
    cout << fixed << setprecision(10) << total_distance * (N-1)  / count << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}