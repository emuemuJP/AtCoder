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

int facctorialMethod(int k){
    int sum = 1;
    for (int i = 1; i <= k; ++i)
    {
        sum *= i;
    }
    return sum;
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
    long P=0, Q=0;
    for(size_t i=0;i<N; i++)
    {
        long p;
        cin >> p;
        P += p * pow(10, N-i-1);
    }
    for(size_t i=0;i<N; i++)
    {
        long q;
        cin >> q;
        Q += q * pow(10, N-i-1);
    }
    cerr << P << ":" << Q << endl;
    string m="";
    for(int i=1; i<=N; i++){
        m+=(char)(i+'0');
    }
    int cnt = 0, ans1 ,ans2;
    while(1){
        cnt++;
        if(stol(m)==P) ans1 = cnt;
        if(stol(m)==Q) ans2 = cnt;
        if(!next_permutation(m.begin(), m.end())) break;
    }
    cout << abs(ans1 - ans2) << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}