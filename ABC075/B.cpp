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
    std::vector<std::vector<char>> mat(H+2, vector<char>(W+2, '.'));
    for(size_t i=1;i<=H; i++)
    {
        string S;
        cin >> S;
        for(size_t j=1;j<=W; j++)
        {
            mat[i][j] = S[j-1];
        }
    }
    for(size_t i=1;i<=H; i++)
    {
        for(size_t j=1;j<=W; j++)
        {
            if(mat[i][j]=='.')
            {
                int count=0;
                for(int ii=-1;ii<=1; ii++)
                {
                    for(int jj=-1;jj<=1; jj++)
                    {
                        if(mat[i+ii][j+jj]=='#') count++;
                    }
                }
                mat[i][j]=count+'0';
            }
        }
    }
    for(size_t i=1;i<=H; i++)
    {
        for(size_t j=1;j<=W; j++)
        {
            cout << mat[i][j];
        }
        cout << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}