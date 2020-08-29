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

class UnionFind
{
private:
    vector<ll> data;
    vector<ll> tree_size;

public:
    UnionFind(ll n)
    {
        data = vector<ll>(n);
        tree_size = vector<ll>(n, 1);
        for (ll i = 0; i < n; ++i)
        {
            data[i] = i;
        }
    }

    ll root(ll a)
    {
        if (data[a] == a) return a;
        else return data[a] = root(data[a]);
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
    long N, M;
    cin >> N >> M;
    vector<ll> A(M), B(M);
    //vector<set<ll>> friends(N);
    UnionFind uf = UnionFind(N);
    for(size_t i=0;i<M; i++)
    {
        cin >> A[i] >> B[i];
        //friends[A[i]-1].insert(B[i]-1);
        //friends[B[i]-1].insert(A[i]-1);
        uf.unite(A[i]-1, B[i]-1);
    }
    ll max_size=0;
    for(size_t i=0;i<N; i++)
    {
        //cerr << i << ":" << uf.get_tree_size(i) << endl;
        max_size = max(max_size, ll(uf.get_tree_size(i)));
    }
    /*
    for(size_t ind=0;ind<N;ind++)
    {
        //cerr << ind+1 << ":";
        for(auto i: friends[ind])
        {
            friends[ind].insert(friends[i].begin(), friends[i].end());
            friends[ind].erase(ind);
        }
        for(auto i: friends[ind])
        {
            cerr << i+1 << " ";
        }
        cerr << endl;
        //max_size = max(max_size, ll(friends[ind].size()));
    }
    */
    cout << max_size << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}