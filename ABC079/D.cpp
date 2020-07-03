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

ll bfs(vector<vector<long>>& c, vector<vector<bool>> ispassed, long num, ll cost, ll min_cost) {
    // 既に探索の場所を1，探索していなかったら0を格納する配列
    min_cost = min(cost + c[num][1], min_cost);
    for(size_t i=0;i<10; i++)
    {
        if(num == 1 || num==i || ispassed[num][i]) continue;
        ll current_cost = cost;
        ispassed[num][i] = true;
        ispassed[i][num] = true;
        current_cost+=c[num][i];
        if(min_cost <= current_cost) continue;
        min_cost = min(bfs(c, ispassed, i, current_cost, min_cost), min_cost);
    }
    return min_cost;
}

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
    std::vector<std::vector<long>> c(10, vector<long>(10, 0));
    for(size_t i=0;i<10; i++)
    {
        for(size_t j=0;j<10; j++)
        {
            cin >> c[i][j];
        }
    }
    //std::vector<std::vector<long>> A(H, vector<long>(W, 0));
    map<ll, ll> A;
    for(size_t i=0;i<H; i++)
    {
        for(size_t j=0;j<W; j++)
        {
            ll a;
            cin >> a;
            if(a != -1) A[a]++;
        }
    }

    //各数字を1に変えるのにかかるコスト
    
    vector<long> num(10);
    for(size_t i=0;i<10; i++)
    {
        vector<vector<bool>> ispassed(c.size(), vector<bool>(c[0].size(), false));
        //cerr << (bfs(c, ispassed, i, 0)) << endl;
        num[i] = bfs(c, ispassed, i, 0, INF);
        cerr << i << ":" << num[i] << endl;
    }
    /*
   for(size_t k=0;k<10; k++)
   {
       for(size_t i=0;i<10; i++)
       {
           for(size_t j=0;j<10; j++)
           {
               c[i][j] = min(c[i][j], c[i][k]+c[k][j]);
           }
       }
   }
   
    for(size_t i=0;i<10; i++)
    {
        cerr << i << ":" << c[i][1] << endl;
    }
    */
    ll total = 0;
    for(auto a : A) total += num[a.first] * a.second;//total += c[a.first][1] * a.second;
    cout << total << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}