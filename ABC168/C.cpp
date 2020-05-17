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
const double PI = 3.141592653589793;

//#define TEST
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    long A, B, H, M;
    cin >> A >> B >> H >> M;
    //A は１分 0.5
    //B は 1分 6
    //A Bの間の角度を出す
    double _A = H * 30 + M * 0.5;
    double _B = M * 6.0;
    double c = min(_A - _B, 360 - (_A - _B));
    // A と B に対応する辺の角度の和
    cout << fixed << setprecision(10) << sqrt(A*A + B*B - 2* A*B*cos(c*PI/180.0)) << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}