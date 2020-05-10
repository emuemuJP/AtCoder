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

ll dfs(vector<long>& C, vector<vector<long>>& A, const long& X, vector<ll> total_A, ll depth, ll c)
{
    for(size_t i=0;i<total_A.size(); i++)
    {
        total_A[i] -= A[depth][i];
        if(total_A[i] < X) return c;
    }
    c -= C[depth];
    ll min_cost = c;
    for(size_t i=depth+1;i<A.size(); i++)
    {
        cerr << i << ":" << A.size() << endl;
        min_cost = min(min_cost, dfs(C, A, X, total_A, i, c));
    }
    return min_cost;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    long N, M, X;
    cin >> N >> M >> X;
    vector<long> C(N);
    vector<vector<long>> A(N, vector<long>(M,0));
    ll total_c = 0; vector<ll> total_A(M);
    for(size_t i=0;i<N; i++)
    {
        cin >> C[i];
        total_c += C[i];
        for(size_t m=0;m<M; m++)
        {
            cin >> A[i][m];
            total_A[m]+= A[i][m];
        }
    }
    bool skillup = true;
    for(size_t i=0;i<M; i++)
    {
        if(total_A[i] < X) skillup = false;
    }

    if(!skillup) cout << "-1" << endl;
    else
    {
        ll min_cost = total_c;
        for(size_t i=0;i<N; i++)
        {
            min_cost = min(min_cost, dfs(C, A, X, total_A, i, total_c));
        }
        cout << min_cost << endl;
    }

#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}