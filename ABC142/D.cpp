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

template <typename T>
inline T gcd(T a, T b) {return b ? gcd(b, a%b) : a;}

template <typename T>
map<T, T> prime_factorization(T n){
    map<T,T> ret;
    for(T i=2;i*i<n;i ++){
        while(n%i==0){
            ret[i] ++;
            n /= i;
        }
    }
    if(n!=1) ret[n]=1;
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    ll A, B;
    cin >> A >> B;
    ll div = gcd(A,B);
    auto divs = prime_factorization(div);
    cout << divs.size()+1 << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}