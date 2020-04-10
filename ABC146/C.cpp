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
const long long INF = (long long)1e18+1;
#define DIV 1000000007
//#define TEST
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    long idx=0;
    ll A, B, X;
    cin >> A >> B >> X;
    // X = A * N + B * d(N)
    ll N = 0;
    ll digit = 0;
    const ll maxN = 1000000000;
    string X_digit = to_string(X);
    size_t max_digit = min(10, max((int)X_digit.size(), 1));
    for(ll digit=max_digit;digit>0; digit--)
    {
        //digit桁数の最小値と最大値を求める
        ll min = pow(10, digit-1);
        if(digit == 1) min = 0;
        ll max = pow(10, digit) - 1;
        if(digit == 10) max = maxN;
#ifdef TEST
        cerr << digit << ":[" << min << "," << max << "]" <<endl;
        cerr << "\t[" << A * min + B * digit << "," << A * (max+1) + B * (digit+1) <<  ")" << endl;
#endif
        if(digit == 10 && X >= A * max + B * 10)
        {
            cout << max << endl;
            return 0;
        }
        else if(X >= A * min + B * digit && X < A * (max+1) + B * (digit+1))
        {
            //N の桁数が求まる
            ll tmp =  (X - B * digit) / A;
            if (to_string(tmp).size() > digit) cout << max << endl;
            else cout << (X - B * digit) / A << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}