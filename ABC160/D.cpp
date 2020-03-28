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
    long N, X, Y;
    cin >> N >> X >> Y;
    vector<long> dist(N);
    long d;
    long start = X-1;
    long end = Y-1;
    for(size_t i=0;i<N; i++)
    {
        for(size_t j=i+1;j<N; j++)
        {
            //cerr << i << "," << j << endl;
            //直接向かう
            // j - i 
            //ショートカット可能
            // |(X-1) - i| + |j - (Y-1)| + 1
            d = j - i;
            if(start >= i && j >= end)
                d = min(d, (long)(start - i + j - end + 1));
            if(i >= start && j >= end)
                d = min(d, (long)(i - start + j - end + 1));
            if(i >= start && end >= j)
                d = min(d, (long)(i - start + end - j + 1));
            if(start >= i && end >= j)
                d = min(d, (long)(start - i + end - j + 1));
            dist[d] ++;
        }
    }

    for(size_t k=1;k<N; k++)
    {
        cout << dist[k] << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}