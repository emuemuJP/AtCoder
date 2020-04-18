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
vector<long> counter(2000001);

void countup (map<long, vector<long>> tree, long p, const long x)
{
    for(size_t elem=0;elem<tree[p].size(); elem++)
    {
        //cerr << tree[p][elem] << ":" << x << endl;
        counter[tree[p][elem]] += x;
        countup(tree, tree[p][elem], x);
    }
    return;
}
//#define TEST
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
    map<long, vector<long>> tree;
    for(size_t i=1;i<=N-1; i++)
    {
        long a,b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b];
    }
    for(size_t i=0;i<Q; i++)
    {
        long p, x;
        cin >> p >> x;
        counter[p] += x;
        countup(tree, p, x);
    }
#ifdef TEST
    cerr << tree.size() << endl;
    for (const auto& elem : tree)
    {
        cerr << elem.first << ":";
        for(size_t j=0;j<elem.second.size(); j++)
        {
            cerr << elem.second[j] << " ";
        }
        cerr << endl;
    }
#endif
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