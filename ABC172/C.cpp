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

/*
ll bfs(vector<ll>& A, vector<ll>& B, ll A_count, ll B_count, ll time, const ll K)
{
    ll total_count = 0, Abook = 0, Bbook = 0;
    if(A.size() > A_count && K >= time + A[A_count])
    {
        Abook = bfs(A, B, A_count+1, B_count, time+A[A_count], K);
    }
    if(B.size() > B_count && K >= time + B[B_count])
    {
        Bbook = bfs(A, B, A_count, B_count+1, time+B[B_count], K);
    }
    total_count = max(Abook, Bbook);
    return max(A_count + B_count, total_count);
}
*/

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    vector<ll> B(M);
    vector<ll> total_A(N+1), total_B(M+1);
    ll AoverK = 0, BoverK = 0;
    total_A[0] = 0;total_B[0] =0;
    for(size_t i=0;i<N; i++)
    {
        cin >> A[i];
        total_A[i+1] = total_A[i] + A[i];
        if(total_A[i+1] <= K) AoverK = i+1;
        //cerr << total_A[i+1] << endl;
    }
    for(size_t i=0;i<M; i++)
    {
        cin >> B[i];
        total_B[i+1] = total_B[i] + B[i];
        if(total_B[i+1] <= K) BoverK = i+1;
        //cerr << total_B[i+1] << endl;
    }
    ll count = 0;
    //cerr << AoverK << ":" << BoverK << endl;
    for(ll i=0;i<=N; i++)
    {
        for(ll j=BoverK;j>=0; j--)
        {
            if(total_A[i] + total_B[j] <= K)
            {
                count=max(count, i+j);
                BoverK=j;
                break;
            }
        }
    }
    //ll count = bfs(A, B, 0, 0, 0, K);
    cout << count << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}