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
    vector<long> A(N);
    long max_num = 0;
    for(size_t i=0;i<N; i++)
    {
        cin >> A[i];
        max_num = max(max_num, A[i]);
    }
    long max_gcd = 0;
    long max_gcd_num = 0;
    for(size_t i=2;i<=max_num; i++)
    {
        long gcd = 0;
        for(size_t j=0;j<N; j++)
        {
            if(A[j] % i == 0) gcd++;
        }
        if(max_gcd < gcd)
        {
            max_gcd = gcd;
            max_gcd_num=i;
        }
    }
    cout << max_gcd_num << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}