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
    string S;
    cin >> S;
    vector<ll> e_count(N), w_count(N);
    for(ll i=1;i<N; i++)
    {
        if(S[i-1]=='W')
        {
            w_count[i]=w_count[i-1]+1;
        }
        else
        {
            w_count[i]=w_count[i-1];
        }
    }
    //cerr << "done west" << endl;
    for(ll i=N-2;i>=0; i--)
    {
        if(S[i+1]=='E')
        {
            e_count[i]=e_count[i+1]+1;
        }
        else
        {
            e_count[i]=e_count[i+1];
        }
    }
    //cerr << "done east" << endl;
    ll min_direction = INF;
    for(size_t i=0;i<N; i++)
    {
        //cerr << e_count[i] << ":" << w_count[i] << endl;
        min_direction = min(min_direction, e_count[i] + w_count[i]);
    }
    cout << min_direction << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}