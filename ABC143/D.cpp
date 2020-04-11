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
    vector<long> L(N);
    for(size_t i=0;i<N; i++)
    {
        cin >> L[i];
    }
    sort(L.begin(), L.end());
    long count = 0;
    for(size_t i=0;i<L.size(); i++)
    {
        for(size_t j=i+1;j<L.size(); j++)
        {
            long a = L[i] + L[j];
            int lowest_index = lower_bound(L.begin(), L.end(), a) - L.begin();
            count +=lowest_index - (j+1);
        }
    }
    cout << count << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}