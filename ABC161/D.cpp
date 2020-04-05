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
#define TEST
vector<ll> v;

void dfs(int k, ll x)
{
    // 初期値 x: 1 ~ 9
    v.push_back(x);
    if(k>=9) return;
    // 1の位
	int a=x%10;
    // 桁下がりしない数:0でない
    // x:10倍した数 + 前後の数
    if(a){
		dfs(k+1, x*10+a-1);
	}
	dfs(k+1, x*10+a);
    // 桁上がりしない数:9でない
	if(a<9){
		dfs(k+1, x*10+a+1);
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
    long idx=0;
    ll K;
    cin >> K;
    for(int i=1; i<=9; i++) dfs(0, i);
	sort(v.begin(), v.end());
    cout<<v[K-1]<<endl;

#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}