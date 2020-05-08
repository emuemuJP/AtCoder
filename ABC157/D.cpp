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

class UnionFind
{
private:
    std::vector<ll> data;
    std::vector<ll> tree_size;

public:
    UnionFind(ll n)
    {
        data = std::vector<ll>(n);
        tree_size = std::vector<ll>(n, 1);
        for (ll i = 0; i < n; ++i)
        {
            data[i] = i;
        }
    }

    ll root(ll a)
    {
        if (data[a] == a)
            return a;
        else
            return data[a] = root(data[a]);
    }

    void unite(ll a, ll b)
    {
        ll root_a = root(a);
        ll root_b = root(b);
        if (root_a == root_b)
            return;
        else
        {
            tree_size[root_b] += tree_size[root_a];
            tree_size[root_a] = 0;
            data[root_a] = root_b;
            return;
        }
        return;
    }

    ll get_tree_size(ll a)
    {
        return tree_size[root(a)];
    }
};


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    long N, M, K;
    cin >> N >> M >> K;
    UnionFind uf((ll)N);
    //vector<pair<long, long>> AB(N);
    //vector<pair<long, long>> CD(N);
    long A, B, C, D;
    vector<vector<long>> relation(N);
    vector<vector<long>> bad_relation(N);
    for(size_t i=0;i<M; i++)
    {
        cin >> A >> B;
        //AB[i] = make_pair(A, B);
        uf.unite(A-1,B-1);
        relation[A-1].push_back(B-1);
        relation[B-1].push_back(A-1);
    }
    for(size_t i=0;i<K; i++)
    {
        cin >> C >> D;
        //CD[i] = make_pair(C, D);
        bad_relation[C-1].push_back(D-1);
        bad_relation[D-1].push_back(C-1);
    }

    for(size_t i=0;i<N; i++)
    {
        ll bad_count=0;
        //cerr << uf.root(i) << endl;
        for (auto b = bad_relation[i].begin(); b != bad_relation[i].end(); b++)
        {
            //cerr << i << ":" << uf.root(i) << "::" << *b << ":" << uf.root(*b) << endl;
            if (uf.root(i) == uf.root(*b))
                bad_count++;
        }
        cout << uf.get_tree_size(i) - 1 - relation[i].size() - bad_count << " ";
    }
    cout << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}