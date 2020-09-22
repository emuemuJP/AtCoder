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
    ll comb=0;
    for(size_t A=1;A<=N; A++)
    {
        comb += N / A;
        if(N - A * (N/A)==0) comb--;
        /*
        for(size_t B=1;B<=N/A; B++)
        {
            //if(A==B) continue;
            if(N - A*B==0) continue;
            cerr << A << "," << B  << "," << N - A*B << endl;
            comb++;
        }
        */
    }
    cout << comb << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}