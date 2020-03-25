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
//#define TEST
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    long idx=0;
    long N, M;
    cin >> N >> M;
    priority_queue<ll> A;
    long num;
    for(size_t i=0;i<N; i++)
    {
        cin >> num;
        A.push(num);
    }

    ll sum=0;
    while(M > 0)
    {
        num = A.top()/2;
        A.pop();
        A.push(num);
        M--;
    }
    for(size_t i=0;i<N; i++)
    {
        sum+= A.top();
        A.pop();
    }
    cout << sum << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}