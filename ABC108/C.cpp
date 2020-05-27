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
    ll a=0, b=0, c=0;
    ll count=0;

    for(ll i=1;i<=N; i++)
    {
        if(i % K == 0) a++;
        if(i % K == K / 2 && K % 2 == 0) b++;
    }
    cout << a*a*a + b*b*b << endl;

   /*
   ll max_multi = 2 * N / K;
    for(size_t i=1;i<=max_multi; i++)
    {
        ll elem = i * K;
        a = elem / 2;
        if(elem != 2 * a) continue;
        for(size_t j=1;j<=i; j++)
        {
            b = j*K - a;
            if(b <= 0) continue;
            for(size_t k=1;k<=j; k++)
            {
                c = k*K - b;
                if(c <= 0 || b < c) continue;
                //cerr << elem << ":" << a << "," << b << "," << c << endl;
                if(a != b && b != c && c != a) count+=6;
                else if(a != b || b != c || c != a) count+=3;
                else count++;
            }
        }
    }

    cout << count << endl;
    */
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}