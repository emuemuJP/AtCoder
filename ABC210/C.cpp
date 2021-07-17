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
#include <set>
#include <unordered_map>
#include <chrono>
#include <numeric>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18+1;
const ll DIV = 1000000007;
//#define TEST

template<class T> bool chmax(T& a, const T b){
    bool isMax = false;
    if(a < b){
        a=b;
        isMax = true;
    }
    return isMax;
}

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
    vector<ll> c(N);
    for(size_t i=0;i<N; i++)
    {
        cin >> c[i];
    }
    ll begin_ = -1;
    queue<ll> q;
    map<ll, ll> m;
    ll max_element = 0;
    for(size_t i=0;i<N; i++)
    {
        //cerr << m.size() << endl;
        //for(auto k:m) cerr << k.first << ":" << k.second << " ";
        //cerr << endl;
        chmax(max_element, ll(m.size()));
        if(i >= K){
            ll key= q.front();
            q.pop();
            m[key]--;
            if(m[key]==0)
            {
                m.erase(key);
                //cerr <<  key << "zero" << endl;
            }
        }
        m[c[i]]++;
        q.push(c[i]);
    }
    //for(auto k:m) cerr << k.first << " ";
    //cerr << endl;
    chmax(max_element, ll(m.size()));
    cout << max_element << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}