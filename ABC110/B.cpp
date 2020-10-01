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
    long N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector<long> x(N);
    vector<long> y(M);
    for(size_t i=0;i<N; i++)
    {
        cin >> x[i];
    }
    for(size_t i=0;i<M; i++)
    {
        cin >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    if(x[N-1] < y[0] && X < x[N-1]+1 && x[N-1]+1 <= Y) cout << "No War" << endl;
    else cout << "War" << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}