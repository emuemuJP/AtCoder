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

void countup(unordered_map<ll, vector<ll>>& tree, vector<ll>& counter, ll prev, ll next)
{
    counter[next] += counter[prev];
    for(auto elem:tree[next])
    {
		if(elem==prev)continue;
		countup(tree, counter, next, elem);
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
    long N,Q;
    cin >> N >> Q;
    unordered_map<ll, vector<ll>> tree;
    vector<ll> counter(N+1);

    for(size_t i=1;i<=N-1; i++)
    {
        ll a,b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    for(size_t i=0;i<Q; i++)
    {
        long p, x;
        cin >> p >> x;
        counter[p] += x;
    }
    countup(tree, counter, 0L, 1L);
    for(size_t i=1;i<=N; i++)
    {
        cout << counter[i] << " ";
    }
    cout << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}