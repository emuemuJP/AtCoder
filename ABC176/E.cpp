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
    long H, W, M;
    cin >> H >> W >> M;
    vector<long> yoko(H);
    vector<long> tate(W);
    long h,w;
    vector<long> target[H];
    vector<long> target_[W];
    for(size_t i=0;i<M; i++)
    {
        cin >> h >> w;
        h--;w--;
        target[h].push_back(w);
        target_[w].push_back(h);
        yoko[h]++;
        tate[w]++;
    }
    vector<long> yoko_ = yoko;
    vector<long> tate_ = tate;

    vector<long>::iterator y_iter = max_element(yoko.begin(), yoko.end());
    size_t y_index = distance(yoko.begin(), y_iter);
    for(auto w : target[y_index]) tate[w]--;
    vector<long>::iterator t_iter = max_element(tate.begin(), tate.end());
    size_t t_index = distance(tate.begin(), t_iter);

    vector<long>::iterator t_iter_ = max_element(tate_.begin(), tate_.end());
    size_t t_index_ = distance(tate_.begin(), t_iter_);
    for(auto h : target_[t_index_]) yoko_[h]--;
    vector<long>::iterator y_iter_ = max_element(yoko_.begin(), yoko_.end());
    size_t y_index_ = distance(yoko_.begin(), y_iter_);
    cout << max(*y_iter + *t_iter, *y_iter_ + *t_iter_) << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}