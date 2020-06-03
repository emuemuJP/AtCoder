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
    ll N;
    cin >> N;
    vector<ll> X(N);
    for(size_t i=0;i<N; i++)
    {
        cin >> X[i];
    }
    vector<ll> sortX = X;
    sort(sortX.begin(), sortX.end());
    //cerr << sortX[N/2] << endl;
    //cerr << sortX[(N-1)/2] << endl;
    // 中央値に選ばれる数は２択
    for(size_t i=0;i<N; i++)
    {
        if(X[i] <sortX[N/2]) cout << sortX[N/2] << endl;
        else cout << sortX[(N-1)/2] << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}