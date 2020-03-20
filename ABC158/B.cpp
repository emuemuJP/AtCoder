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
    long N, A, B;
    cin >> N >> A >> B;
    long loop = N / (A + B);
    long residual = N - (A + B) * loop;
    if (A >= residual)
        cout << A * loop + residual << endl;
    else
        cout << A * loop + A << endl;

    return 0;
}