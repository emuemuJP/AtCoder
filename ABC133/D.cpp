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
    vector<long> A(N);
    ll init_rain = 0;
    for(size_t i=0;i<N; i++)
    {
        //ダムの水の量は i の山の雨の量 / 2 + (i + 1) の山の雨の量 / 2
        cin >> A[i];
        if(i % 2 == 0) init_rain += A[i];
        else init_rain -= A[i];
    }
    cerr << init_rain << endl;
    long prev_rain, current_rain;
    for(size_t i=0;i<N; i++)
    {
        if(i == 0)
        {
            cout << init_rain << " ";
            prev_rain = init_rain;
        }else
        {
            current_rain = 2 * A[i-1] - prev_rain;
            cout << current_rain << " ";
            prev_rain = current_rain;
        }
    }
    cout << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}