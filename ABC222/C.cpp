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
#include <set>
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
    ll N,M;
    cin >> N >> M;
    std::vector<std::vector<ll>> B(N, vector<ll>(M));
    bool first = true;
    bool A_cond = true;
    ll A_i,A_j;
    for(size_t i=0;i<N; i++)
    {
        for(size_t j=0;j<M; j++)
        {
            cin >> B[i][j];
            if(first)
            {
                first = false;
                A_i = B[i][j] / 7 + 1;
                A_j = (B[i][j]) % 7;
                if (A_j == 0) A_j=7;
                //cerr << A_i << ":" << A_j << endl;
                if(A_j + M > 8) A_cond=false;
            }

            if(i>0 && B[i][j]!=B[i-1][j] + 7) A_cond=false;
            if(j>0 && B[i][j]!=B[i][j-1] + 1) A_cond=false;
        }
    }
    if(A_cond) cout << "Yes" << endl;
    else cout << "No" << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}