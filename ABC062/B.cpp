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
    long H,W;
    cin >> H >> W;
    vector<vector<char>> image(H+2, vector<char>(W+2, '#'));
    for(size_t i=1;i<=H; i++)
    {
        for(size_t j=1;j<=W; j++)
        {
            cin >> image[i][j];
        }
    }
    for(size_t i=0;i<H+2; i++)
    {
        for(size_t j=0;j<W+2; j++)
        {
            cout << image[i][j];
        }
        cout << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}