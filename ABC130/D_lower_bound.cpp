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
    long N,K;
    cin >> N >> K;
    vector<long> a(N);
    vector<long> s(N+1);

    for(size_t i=0;i<N; i++)
    {
        cin >> a[i];
        s[i+1] = s[i] + a[i];
    }
    long ans=0;
    for(size_t i=0;i<N; i++)
    {
        cerr << s[i]+K << ":" << s.end() - lower_bound(s.begin(), s.end(), s[i]+K) << endl;
        ans+=s.end() - lower_bound(s.begin(), s.end(), s[i]+K);
    }
    cout << ans << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}