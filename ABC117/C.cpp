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

bool compare_by_pair(pair<long,long> a, pair<long,long> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }
    return false;
}

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
    vector<long> X(M);
    for(size_t i=0;i<M; i++)
    {
        cin >> X[i];
    }
    sort(X.begin(), X.end());

    vector<pair<long, long>> distance(M-1);
    for(size_t i=1;i<M; i++)
    {
        distance[i-1] = make_pair(i, X[i] - X[i-1]);
    }
    sort(distance.rbegin(), distance.rend(), compare_by_pair);
    //最初に置くコマを決める
    long counter = 1;
    long short_cut = 0;
    for(const auto& d:distance)
    {
        if(counter < N)
        {
            short_cut += d.second;
            counter++;
        }
        else break;
    }
    cout << (X.back() - X.front()) - short_cut << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}