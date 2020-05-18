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
    long N, M;
    cin >> N >> M;
    ll A, B;
    vector<vector<ll>> Node(N+1);
    for(size_t i=0;i<M; i++)
    {
        cin >> A >> B;
        Node[A].push_back(B);
        Node[B].push_back(A);
    }

    queue<ll> q;
    q.push(1);
    vector<ll> ans(N+1);
    ans[1]=1;

    while(!q.empty())
    {
        //Node 1からスタート
        ll index = q.front();q.pop();
        for(size_t i=0;i<Node[index].size(); i++)
        {
            //探索してなければ足す
            if(!ans[Node[index][i]])
            {
                ans[Node[index][i]] = index;
                q.push(Node[index][i]);
            }
        }
    }

    cout << "Yes" << endl;
    for(size_t i=2;i<=N; i++)
    {
        cout << ans[i] << endl;
    }

#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}