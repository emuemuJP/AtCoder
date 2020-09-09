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
    ll T, A;
    cin >> T >> A;
    vector<ll> H(N);
    ll ind = -1;
    double min_diff = INF;
    for(size_t i=0;i<N; i++)
    {
        cin >> H[i];
        double degree_diff = double(abs(T - 0.006*H[i] - A));
        if(min_diff > degree_diff)
        {
            min_diff = min(min_diff, degree_diff);
            ind=i;
        }
    }
    cout << ind+1 << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}