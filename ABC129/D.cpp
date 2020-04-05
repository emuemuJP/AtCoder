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


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    long idx=0;
    long H, W;
    cin >> H >> W;
    std::vector<std::vector<string>> mat(H, vector<string>(W, ""));
    for(size_t i=0;i<H; i++)
    {
        string line;
        cin >> line;
        for(size_t j=0;j<W; j++)
        {
            mat[i][j] = line[j];
        }
    }
    std::vector<std::vector<long>> mat_count(H, vector<long>(W, 0));
    for(size_t i=0;i<H; i++)
    {
        long count = 0;
        for(size_t j=0;j<W; j++)
        {
            if(mat[i][j] == "#") count = 0;
            else count++;
            mat_count[i][j] += count;
        }
    }
    for(size_t i=0;i<H; i++)
    {
        long count = 0;
        for(size_t j=W-1;j>=0; j--)
        {
            if(mat[i][j] == "#") count = 0;
            else count++;
            mat_count[i][j] += count;
            if(j==0) break;
        }
    }
    for(size_t j=0;j<W; j++)
    {
        long count = 0;
        for(size_t i=0;i<H; i++)
        {
            if(mat[i][j] == "#") count = 0;
            else count++;
            mat_count[i][j] += count;
        }
    }
    long max_path=0;
    for(size_t j=0;j<W; j++)
    {
        long count = 0;
        for(size_t i=H-1;i>=0; i--)
        {
            if(mat[i][j] == "#") count = 0;
            else count++;
            mat_count[i][j] += count;
            max_path = max(max_path, -3+mat_count[i][j]);
            if(i==0) break;
        }
    }

    cout << max_path << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}