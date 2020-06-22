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
    ll count=0;
    vector<ll> A(N);
    ll Amax = pow(10,6);
    vector<ll> divs(Amax+1);
    for(size_t i=0;i<N; i++)
    {
        cin >> A[i];
        divs[A[i]]++;
    }
    ll div_count = 0;
    for(size_t i=0;i<=Amax; i++)
    {
        if(divs[i]==0) continue;
        if(divs[i]==1) div_count++;
        for(size_t j=2;i*j<=Amax; j++)
        {
            divs[i*j]=0;
        }
    }
    cout << div_count << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}