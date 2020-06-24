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
    vector<ll> C(N);
    vector<ll> S(N);
    vector<ll> F(N);
    for(size_t i=0;i<N-1; i++)
    {
        //次の駅までC秒
        //S秒後に発車
        //F秒おきに発車
        cin >> C[i] >> S[i] >> F[i];
    }
    for(size_t i=0;i<N; i++)
    {
        if(i==N-1) cout << 0 << endl;
        else
        {
            ll time = S[i] + C[i];
            for(size_t j=i+1;j<N-1; j++)
            {
                if(time < S[j]) time = S[j];
                else if(time % F[j] == 0);
                else time+=F[j]-time%F[j];
                time+=C[j];
            }
            cout << time << endl;
        }
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}