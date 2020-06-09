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
    //余りはK以上
    //aはN以下 bはKより大きくN未満
    ll counter = 0;
    /*
    for(ll i=K;i<=N;i++)
    {
        // a = i として、
        //余りがKの時のありうる組み合わせが
        //bがK+1, K+2, ... , の時なので
        // N - i が商が0のときの割ることのできる数
        // min が iで maxが N
        counter += N - i;
        //割ったときの商が１以上の時の処理
        // min が 1 で maxが i-1
        // 割った余りがK以上であればよい
        for(size_t j=1;j<i; j++)
        {
            if(i % j >= K) counter++;
        }
        //cerr << i << ":" << counter << endl;

    }
    */
    for(ll b=1;b<=N;b++)
    {
        //bを固定してaを自由にする
        //bがK以上のときN/b回条件に一致するものが存在し、あまりの部分にいくつあるかをカウントすればよい
        counter+= (N/b)*max((b-K), 0ll) + max(N%b -K +1, 0ll);
        //cerr << b << ":" << counter << endl;
    }
    if(K==0) counter = N*N;
    cout << counter << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}