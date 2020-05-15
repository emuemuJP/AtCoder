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

vector<ll> _dfs(ll start, const ll& depth, vector<ll>& burger)
{
    vector<ll> next_burger;
    if(start != depth)
    {
        if(start == 0)
        {
            next_burger.push_back(1);
        }
        else
        {
            next_burger.push_back(0);
            next_burger.insert(next_burger.end(), burger.begin(), burger.end());
            next_burger.push_back(1);
            next_burger.insert(next_burger.end(), burger.begin(), burger.end());
            next_burger.push_back(0);
        }
        start++;
        burger = _dfs(start, depth, next_burger);
    }
    return burger;
}

ll dfs(ll N, ll X, vector<ll> & all, vector<ll>& p)
{
    if(N==0)
    {
        if(X<=0) return 0;
        else return 1;
    }else if(X <= 1 + all[N-1])
    {
        return dfs(N-1, X-1, all, p);
    }else
    {
        return p[N-1] + 1 + dfs(N-1, X - all[N-1] - 2, all, p);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    long N, X;
    cin >> N >> X;
    // 層の数は 2(L-1)+3
    // レベルあたりのパティの数は 2(L-1)+1
    vector<ll> all(N);
    vector<ll> p(N);
    for(size_t i=0;i<N; i++)
    {
        if(i==0)
        {
            all[0] = 1;
            p[0] = 1;
        }else
        {
            all[i] = 2 * all[i-1] + 3;
            p[i] = 2* p[i-1] + 1;
        }
    }
    //vector<ll> burger;
    //burger = dfs(N,X);
    //cerr << burger.size() << endl;
    cout << dfs(N, X, all, p) << endl; 
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}