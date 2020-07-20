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
    vector<ll> a(N);
    bool times = true;
    ll times4=0;
    ll times2=0;
    ll other=0;
    for(size_t i=0;i<N; i++)
    {
        cin >> a[i];
        if(a[i] % 4 == 0) times4++;
        else if(a[i] % 2 == 0) times2++;
        else other++;
    }
    //cerr << times4 << ":" << times2 << ":" << other << endl;
    if(other>0)
    {
        if(other+times2%2 <= times4+1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else cout << "Yes" << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}