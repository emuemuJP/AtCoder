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
#include <set>
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
    long N;
    cin >> N;
    vector<vector<long>> Graph(N);
    long a[N-1], b[N-1];
    //辺ごとの色を登録
    vector<long> color(N);
    for(size_t i=0;i<N-1; i++)
    {
        cin >> a[i] >> b[i]; a[i]--;b[i]--;
        //各頂点の持つ辺を登録する
        Graph[a[i]].push_back(i);
        Graph[b[i]].push_back(i);
    }
    ll max_color = 0;
    for(auto v: Graph)
    {
        max_color = max(max_color, (ll)v.size());
    }
    cout << max_color << endl;

    for(size_t i=0;i<N; i++)
    {
        set<ll> s;
        //頂点 Graph[i] の持つ辺が既に別の頂点によって塗られている場合はその色を保持しておく
        for(auto e : Graph[i]) if(color[e] != -1) s.insert(color[e]);
        ll count = 1;
        for(auto e : Graph[i]){
            if(color[e] == 0){
                //頂点 Graph[i] の持つ各辺について色を塗っていく
                //色は小さな数から順に塗っていくが既に塗られている場合は新たな色を割り当てる
				while(s.count(count)) count++;
				s.insert(count);
                //辺eを塗る
				color[e] = count;
			}
		}
    }
    for(int i=0;i<N-1;i++) cout << color[i] << endl;

#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}