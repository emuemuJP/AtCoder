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
#define PI 3.141592653589793
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    long idx=0;
    long a, b, x;
    cin >> a >> b >> x;
    long floor = a * b;
    double height =  2.0 * x / floor;
    if(height > a)
    {
        double residual = x - floor * a / 2.0;
        double second_height = 2.0 * residual / (a * a);
        cout << fixed << setprecision(10) << atan2f(b - second_height, a) * 180.0 / PI << endl;
    }
    else
    {
        cout << fixed << setprecision(10) << 90.0 - atan2f(height, b) * 180.0 / PI << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}