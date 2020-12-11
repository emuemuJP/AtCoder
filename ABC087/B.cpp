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
    long A, B, C, X;
    cin >> A >> B >> C >> X;
    ll comb_num = 0;
    for(size_t i=0;i<=A; i++)
    {
        for(size_t j=0;j<=B; j++)
        {
            for(size_t k=0;k<=C; k++)
            {
                if(i*500 + j*100 + k*50 == X) comb_num++;
            }
        }
    }
    cout << comb_num << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}