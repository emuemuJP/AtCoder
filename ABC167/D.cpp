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

struct Tree
{
    ll id;
    ll toward;
    ll from;
    ll res;
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    vector<Tree> trees(N);
    for(size_t i=0;i<N; i++)
    {
        cin >> A[i];A[i]--;
        Tree t = {(ll)i, A[i], -1, -1};
        trees[i] = t;
    }
    ll from_i = 0;
    ll i = trees[0].toward;
    ll loop_cost = 1;
    ll loop_start_point = -1;
    while(loop_start_point != i)
    {
        if(trees[i].from != -1 && loop_start_point == -1)
        {
            loop_start_point = i;
            trees[loop_start_point].res = 0;
            K--;
            //cerr << "start:" << loop_start_point << endl;
        }
        else if (loop_start_point == -1) K--;

        if(loop_start_point != i && loop_start_point != -1)
        {
            //cerr << i << ":" <<  loop_cost << endl;
            trees[i].res = loop_cost;
            loop_cost++;
        }
        if(K == 0) {cout << i+1 << endl; return 0;}
        //cerr << "from:" << from_i << ":i:" << i << ":toward:" << trees[i].toward << ":K:" << K << endl;
        trees[i].from = from_i;
        from_i = i;
        i = trees[i].toward;
    }
    //cerr << K << ":" <<loop_cost << endl;
    K = K % loop_cost;
    //cerr << loop_start_point << ":" << loop_cost << ":" <<  K << endl;
    for(size_t i=0;i<N; i++)
    {
        //cerr << i << ":" << trees[i].res << endl;
        if(K == trees[i].res)
        {
            cout << i+1 << endl;
            break;
        }
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}