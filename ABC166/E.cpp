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
    long N;
    cin >> N;
    vector<long> A(N);
    for(size_t i=0;i<N; i++)
    {
        long a;
        cin >> A[i];
    }

    //番号の差の絶対値と身長の和なので順番は関係ない
    ll count = 0;
    vector<ll> L(N);
    vector<ll> R(N);
    for(size_t i=0;i<N; i++)
    {
        if (A[i]+i<N) L[A[i]+i]++;
        if (0<=i-A[i]&&i-A[i]<N) R[i-A[i]]++;
    }
    for(size_t i=0;i<N; i++)
    {
        count += L[i] * R[i];
    }
    cout << count << endl;
    /*
    sort(A.begin(), A.end(), compare_by_pair);
    for(const auto& a:A)
    {
        cout << a.first << ":" << a.second << endl;
    }
    auto endA = lower_bound(A.begin(), A.end(), make_pair(-INF, N));
    for(auto it = A.begin(); it != endA; ++it){
        cout << (*it).first << ":" <<(*it).second << endl;
    }
    */
    /*
    for(size_t i=0;i<N; i++)
    {
        for(size_t j=i+1;j<N; j++)
        {
            if(j - i == A[i] + A[j]) count++;
        }
    }
    */
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}