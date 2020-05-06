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

//priority que pair
using llpair = pair<ll,ll>;
bool operator>(const llpair a,const llpair b){return a.second > b.second;};

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
    //vector<priority_queue<llpair,vector<llpair>,greater<llpair>>> city(N);
    // mapだと間に合わない
    //vector<map<ll, ll>> city(N);
    vector<vector<ll>> city(N);
    ll P[M], Y[M];
    //std::distance(std::begin(myMap), myMap.find("myKey"))
    for(size_t i=0;i<M; i++)
    {
        cin >> P[i] >> Y[i];
        city[P[i]-1].push_back(Y[i]);
    }
    for(size_t i=0;i<N; i++)
    {
        cerr << city[i].size() << endl;
        sort(city[i].begin(), city[i].end());
    }
    /*
    for(size_t i=0;i<N; i++)
    {
        for(const auto& m:city[i])
        {
            //cerr << i << ":" << m.first << ":" << m.second << endl;
            cerr << i << ":" << m << endl;
        }
    }
    */
    for(size_t i=0;i<M; i++)
    {
        cout << setw(6) << setfill('0') << P[i];
        cout << setw(6) << setfill('0') << distance(city[P[i]-1].begin(), lower_bound(city[P[i]-1].begin(), city[P[i]-1].end(), Y[i])) + 1 << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}