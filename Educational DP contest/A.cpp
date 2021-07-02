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

vector<ll> cost(100000, INF);
vector<ll> h(100000, INF);


// bool min_bool(ll& lhs,const ll rhs)
// {
//     bool isMin = false;
//     if(lhs > rhs)
//     {
//         lhs = rhs;
//         isMin = true;
//     }
//     return isMin;
// }

// void dp(int i, const ll& N)
// {
//     bool isMin = false;
//     for(size_t j=1;j<=2; j++)
//     {
//         if(i+j >= N) return;
//         isMin = min_bool(cost[i+j], cost[i] + abs(h[i] - h[i+j]));
//         if(isMin) dp(i+j, N);
//     }
// }

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
    for(size_t i=0;i<N; i++)
    {
        cin >> h[i];
    }
    cost[0] = 0;

    for(size_t i=1;i<N; i++)
    {
        if(i == 1) cost[i] = abs(h[i] - h[i-1]);
        else cost[i] = min(cost[i-1] + abs(h[i] - h[i-1]),
                           cost[i-2] + abs(h[i] - h[i-2]));
    }

    cout << cost[N-1] << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}