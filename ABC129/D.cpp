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
    std::vector<std::vector<long>> mat_L(H, vector<long>(W, 0));
    for(size_t i=0;i<H; i++)
    {
        long count = 0;
        for(size_t j=0;j<W; j++)
        {
            if(mat[i][j] == "#") count = 0;
            else count++;
            mat_L[i][j] = count;
        }
    }
    std::vector<std::vector<long>> mat_R(H, vector<long>(W, 0));
    for(size_t i=0;i<H; i++)
    {
        long count = 0;
        for(size_t j=W-1;j>=0; j--)
        {
            if(mat[i][j] == "#") count = 0;
            else count++;
            mat_R[i][j] = count;
            if(j==0) break;
        }
    }
    std::vector<std::vector<long>> mat_D(H, vector<long>(W, 0));
    for(size_t j=0;j<W; j++)
    {
        long count = 0;
        for(size_t i=0;i<H; i++)
        {
            if(mat[i][j] == "#") count = 0;
            else count++;
            mat_D[i][j] = count;
        }
    }
    std::vector<std::vector<long>> mat_U(H, vector<long>(W, 0));
    for(size_t j=0;j<W; j++)
    {
        long count = 0;
        for(size_t i=H-1;i>=0; i--)
        {
            if(mat[i][j] == "#") count = 0;
            else count++;
            mat_U[i][j] = count;
            if(i==0) break;
        }
    }
    long max_path = 0;
    for(size_t i=0;i<H; i++)
    {
        for(size_t j=0;j<W; j++)
        {
            if(mat[i][j] == ".")
            {
                max_path = max(max_path, -3+mat_L[i][j]+mat_R[i][j]+mat_U[i][j]+mat_D[i][j]);
            }
        }
    }
    cout << max_path << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}