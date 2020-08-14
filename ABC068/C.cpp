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
    std::vector<std::vector<long>> mat(N, vector<long>());
    long a, b;
    for(size_t i=0;i<M; i++)
    {
        cin >> a >> b;
        a--;b--;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
    bool ok=false;
    for(size_t i=0;i<mat[N-1].size(); i++)
    {
        long next_point = mat[N-1][i];
        cerr << next_point << endl;
        for(size_t j=0;j<mat[next_point].size(); j++)
        {
            long last_point = mat[next_point][j];
            cerr <<  last_point << endl;
            if(mat[next_point][j]==0) ok =true;
        }
    }
    if(ok) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}