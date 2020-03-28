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
    long K, N;
    cin >> K >> N;
    vector<long> A(N);
    for(size_t i=0;i<N; i++)
    {
        cin >> A[i];
    }
    vector<long> dist(N);
    for(size_t i=0;i<N; i++)
    {
        if(i!=N-1) dist[i] = A[i+1] - A[i];
        else dist[i] = K - A[i] + A[0];
        //cerr << dist[i] << endl;
    }
    sort(dist.begin(), dist.end());
    long total = 0;
    for(size_t i=0;i<N-1; i++)
    {
        total += dist[i];
    }
    cout << total << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}