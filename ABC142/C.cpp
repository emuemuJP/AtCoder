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
const long long INF = (long long)1e18+1;
#define DIV 1000000007

bool compare_by_pair(pair<long,long> a, pair<long,long> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }
    return a.second == b.second;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    long idx=0;
    long N;
    cin >> N;
    long a;
    vector<pair<long, long>> A(N);
    for(size_t i=1;i<=N; i++)
    {
        //出席番号 i の出席したときの教室の人数 A[i]
        cin >> a;
        A[i-1] = make_pair(long(i), a);
    }
    sort(A.begin(), A.end(), compare_by_pair);
    for(size_t i=0;i<N; i++)
    {
        cout << A[i].first << " ";
    }
    cout << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}