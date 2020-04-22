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
    long N;
    cin >> N;
    vector<ll> A(N);
    ll min_hp = 1e18;
    ll min_hp_index;
    for(size_t i=0;i<N; i++)
    {
        cin >> A[i];
        min_hp = min(min_hp, A[i]);
        if(min_hp == A[i]) min_hp_index = i;
    }
    bool attack = true;
    while(attack)
    {
        ll next_min_hp = 1e18;
        ll next_min_hp_index;
        attack = false;
        for(size_t i=0;i<N; i++)
        {
            if(i == min_hp_index) continue;
            ll remain_hp = A[i] % min_hp;
            if(A[i] / min_hp > 0 && remain_hp >= 0)
            {
                A[i] = remain_hp;
                attack = true;
                if(remain_hp > 0)
                {
                    next_min_hp = min(min_hp, remain_hp);
                    if(A[i] == next_min_hp) next_min_hp_index = i;
                }
            }
        }
        min_hp = min(min_hp, next_min_hp);
        if(min_hp == next_min_hp) min_hp_index = next_min_hp_index;
    }
    cout << min_hp << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}