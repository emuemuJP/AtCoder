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
    long N, K;
    cin >> N >> K;
    long total;
    deque<long> _a(N);
    for(size_t i=0;i<N; i++)
    {
        cin >> _a[i];
        total += _a[i];
    }
    long count=0;
    long sum=0;
    long idx = 0;
    for(size_t i=0;i<N; i++)
    {
        while(sum < K)
        {
            if(idx==N) break;
            sum+=_a[idx];
            idx++;
        }
        if(sum < K) break;
        count+=N-idx+1;
        sum-=_a[i];
    }

    cout << count << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}