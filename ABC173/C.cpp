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
    long H,W,K;
    cin >> H >> W >> K;
    std::vector<std::vector<char>> c(H, vector<char>(W, ' '));
    long count=0;
    for(size_t i=0;i<H; i++)
    {
        string line;
        cin >> line;
        for(size_t j=0;j<W; j++)
        {
            if(line[j] == '#') count++;
            c[i][j] = line[j];
        }
    }
    cerr << count << endl;
    /*
    for(size_t i=0;i<H; i++)
    {
        for(size_t j=0;j<W; j++)
        {
            cerr << c[i][j] << " ";
        }
        cerr << endl;
    }
    */
   ll comb_count=0;
    for(ll k=0;k<(1<<(H+W)); k++)
    {
        //cerr << k << endl;
        ll erase = 0;
        //cerr << k << ">>" << endl;
        for(size_t i=0;i<H;i++)
        {
            //cerr << i << endl;
            for(size_t j=H;j<W+H; j++)
            {
                //cerr << "i:" << i << ":" << (k>>i) << " " << "j:" << j << ":" << (k>>j) << endl;

                if(((k>>i) & 1 || (k>>j) & 1) && c[i][j-H]=='#') erase++;
            }
        }
        //cerr << erase << ":" << count-erase << endl;
        if(count-erase == K) comb_count++;
    }
    cout << comb_count << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}