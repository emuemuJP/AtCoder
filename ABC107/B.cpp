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
    long H, W;
    cin >> H >> W;
    std::vector<std::vector<char>> mat(H, vector<char>(W));
    for(size_t i=0;i<H; i++)
    {
        string line;
        cin >> line;
        for(size_t c=0;c<line.size(); c++)
        {
            mat[i][c] = line[c];
        }
    }
    vector<int> row_skip;
    vector<int> col_skip;

    for(size_t i=0;i<H; i++)
    {
        bool skip = true;
        for(size_t j=0;j<W; j++)
        {
            if(mat[i][j] == '#')
            {
                skip = false;
                break;
            }
            //cerr << mat[i][j] << " ";
        }
        if(!skip) row_skip.push_back(i);
        //cerr << endl;
    }

    for(size_t j=0;j<W; j++)
    {
        bool skip = true;
        for(size_t i=0;i<H; i++)
        {
            if(mat[i][j] == '#')
            {
                skip = false;
                break;
            }
        }
        if(!skip) col_skip.push_back(j);
    }

    for(size_t i=0;i<row_skip.size(); i++)
    {
        for(size_t j=0;j<col_skip.size(); j++)
        {
            cout << mat[row_skip[i]][col_skip[j]];
        }
        cout << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}