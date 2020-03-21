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
using namespace std;
using ll = long long;
const long long INF = (long long)1e18+1;
#define DIV 1000000007
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    long idx=0;
    long A, B;
    cin >> A >> B;
    long x_A, x_B, x_A_max, x_B_max;
    //A = x * 1.08 - x = 0.08 * x = 8  / 100 * x ⇔ x = A * 100 / 8
    //B = x * 1.10 - x = 0.10 * x = 10 / 100 * x ⇔ x = B * 100 / 10
    //if(A * 100 % 8)
    if(A * 100.0 / 8 > A * 100 / 8) x_A = A * 100 / 8 + 1;
    else    x_A = A * 100 / 8;
    x_B = B * 10;
    cerr << x_A * 0.08 << ":" << A << ":" << x_A << endl;
    x_A_max = (A + 1) * 100 / 8;
    x_B_max = (B + 1) * 10;
    //cerr << x_A << ":" << x_B << endl;
    //cerr << x_A_max << ":" << x_B_max << endl;
    long lowest_x=-1;
    // x_A <= lowest_x < x_A_max and x_B <= lowest_x < x_B_max
    for(size_t i=x_A;i<x_A_max; i++)
    {
        if(x_B <= i && i < x_B_max)
        {
            lowest_x = i;
            break;
        }
    }
    cout << lowest_x << endl;
    return 0;
}