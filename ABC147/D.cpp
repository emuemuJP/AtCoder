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
    long N;
    cin >> N;
    vector<bitset<62>> A(N);
    for(size_t i=0;i<N; i++)
    {
        ll a;
        cin >> a;
        A[i] = bitset<62>(a);
    }
    ll total = 0;
    for(size_t b=0;b<62; b++)
    {
        ll zero_count = 0;
        ll one_count = 0;
        for(size_t i=0;i<N; i++)
        {
            if(A[i][b]) one_count++;
            else zero_count++;
        }
        total += (one_count * zero_count % DIV) * ((ll)pow(2, int(b)) % DIV) % DIV;
    }
    cout << total % DIV << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}