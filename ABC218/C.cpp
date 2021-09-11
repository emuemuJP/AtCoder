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

template<class T> bool chmin(T& a, const T b){
    bool isMin = false;
    if(a > b){
        a=b;
        isMin = true;
    }
    return isMin;
}

template<class T> bool chmax(T& a, const T b){
    bool isMax = false;
    if(a < b){
        a=b;
        isMax = true;
    }
    return isMax;
}

bool check(const std::vector<pair<ll,ll>>& S_, const std::vector<pair<ll,ll>>& T_)
{
    bool ok = true;
    for(int i=0;i<S_.size();i++)
    {
        ok = false;
        for(size_t j=0;j<T_.size(); j++)
        {
            if(S_[i].first == T_[j].first && S_[i].second == T_[j].second)
            {
                ok = true;
                break;
            }
        }
        if(!ok) break;
    }
    return ok;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    ll N;
    cin >> N;
    std::vector<std::vector<char>> S(N, vector<char>(N));
    std::vector<pair<ll,ll>> S_;
    ll S_lower_i = 201;
    ll S_lower_j = 201;
    ll S_upper_i = -1;
    ll S_upper_j = -1;
    for(ll i=0;i<N; i++)
    {
        for(ll j=0;j<N; j++)
        {
            cin >> S[i][j];
            if(S[i][j]=='#')
            {
                chmin(S_lower_i, i);
                chmin(S_lower_j, j);
                chmax(S_upper_i, i);
                chmax(S_upper_j, j);
                S_.push_back(make_pair(i,j));
            }
        }
    }
    S_upper_i -= S_lower_i;
    S_upper_j -= S_lower_j;
    for(size_t i=0;i<S_.size(); i++)
    {
        S_[i].first -=S_lower_i;
        S_[i].second -=S_lower_j;
    }

    std::vector<std::vector<char>> T(N, vector<char>(N));
    std::vector<pair<ll,ll>> T_;
    ll T_lower_i = 201;
    ll T_lower_j = 201;
    ll T_upper_i = -1;
    ll T_upper_j = -1;
    for(ll i=0;i<N; i++)
    {
        for(ll j=0;j<N; j++)
        {
            cin >> T[i][j];
            if(T[i][j]=='#')
            {
                chmin(T_lower_i, i);
                chmin(T_lower_j, j);
                chmax(T_upper_i, i);
                chmax(T_upper_j, j);
                T_.push_back(make_pair(i,j));
            }
        }
    }
    T_upper_i -= T_lower_i;
    T_upper_j -= T_lower_j;

    for(size_t i=0;i<T_.size(); i++)
    {
        T_[i].first -=T_lower_i;
        T_[i].second -=T_lower_j;
        //cerr << T_[i].first << ":" << T_[i].second << endl;
    }

    if(S_.size() != T_.size())
    {
        cout << "No" << endl;
        return 0;
    }
    if(check(S_, T_)){
        cout << "Yes" << endl;
        return 0;
    }

    //左90
    //cerr << "90:" << T_upper_i << ":" << T_upper_j << endl;
    for(size_t i=0;i<T_.size(); i++)
    {
        ll tmp = T_[i].first;
        T_[i].first = T_upper_j - T_[i].second;
        T_[i].second =tmp;
        //cerr << T_[i].first << ":" << T_[i].second << endl;
    }
    ll tmp;
    tmp = T_upper_i;
    T_upper_i = T_upper_j;
    T_upper_j = tmp;
    if(check(S_, T_)){
        cout << "Yes" << endl;
        return 0;
    }

    // 270
    //cerr << "270:" << T_upper_i << ":" << T_upper_j << endl;
    for(size_t i=0;i<T_.size(); i++)
    {
        T_[i].first = T_upper_i - T_[i].first;
        T_[i].second = T_upper_j - T_[i].second;
        //cerr << T_[i].first << ":" << T_[i].second << endl;
    }
    if(check(S_, T_)){
        cout << "Yes" << endl;
        return 0;
    }

    //180
    //cerr << "180:" << T_upper_i << ":" << T_upper_j << endl;
    for(size_t i=0;i<T_.size(); i++)
    {
        ll tmp = T_upper_i - T_[i].first;
        T_[i].first = T_[i].second;
        T_[i].second =tmp;
        //cerr << T_[i].first << ":" << T_[i].second << endl;
    }
    tmp = T_upper_i;
    T_upper_i = T_upper_j;
    T_upper_j = tmp;
    if(check(S_, T_)){
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
    #ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}