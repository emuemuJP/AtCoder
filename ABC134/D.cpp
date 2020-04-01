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
    vector<long> a(N+1);
    for(size_t i=1;i<=N; i++)
    {
        cin >> a[i]; //iの倍数の和の２の剰余;
    }
    vector<long> b(N+1);
    long total = 0;
    bool ok = false;
    for(size_t i=N;i>0; i--)
    {
        long sum = 0;
        if(N/i == 1) b[i] = a[i];
        else
        {
            for(size_t j=2;j<=N/i; j++)
            {
                sum += b[i * j];
            }
            if(a[i] == sum % 2) b[i] = 0;
            else b[i] = 1;
        }
        if(b[i] == 1) total++;
    }
    cout << total << endl;
    if(total != 0)
    {
        for(size_t i=1;i<=N; i++)
        {
            if(b[i]== 1) cout << i << " ";
        }
        cout << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}