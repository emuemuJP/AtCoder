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
    long N, K;
    cin >> N >> K;
    map<long, long> A;
    for(size_t i=0;i<N; i++)
    {
        long a;
        cin >> a;
        A[a]++;
    }
    vector<long> num;
    for(auto a:A) num.push_back(a.second);
    sort(num.begin(), num.end());
    long total=0;
    if(A.size()>K)
    {
        for(ll i=0;i<A.size()-K; i++)
        {
            total+=num[i];
        }
    }
    cout << total << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}