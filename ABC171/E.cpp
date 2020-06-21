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
    ll N;
    cin >> N;
    vector<bitset<30>> a(N);
    ll A;
    vector<ll> bits(30);
    for(size_t i=0;i<N; i++)
    {
        cin >> A;
        a[i] = bitset<30>(A);
        for(ll b=29;b>=0; b--)
        {
            bits[b]+=a[i][b];
        }
    }
    ll count = 0;
    //while(pow(2, count) < pow(10, 9)) count++;
    //cerr << count << ":" << pow(2,count) << endl;
    //for(auto i:a) cerr << i << endl;
    //for(ll i=29;i>=0; i--)
    //{
    //    cerr << bits[i];
    //}
    //cerr << endl;
    for(size_t i=0;i<N; i++)
    {
        string bit = "000000000000000000000000000000";
        for(ll b=29;b>=0; b--)
        {
            if(bits[b] % 2 == 0)
            {
                if(a[i][b]) bit[29 - b] = '1';
            }
            else
            {
                if(!a[i][b]) bit[29 - b] = '1';
            }
        }
        //cerr << bit << endl;
        cout << bitset<30>(bit).to_ullong() << " ";
    }
    cout << endl;
    //std::bitset<8> bs("00000011");
    //std::bitset<8> bs2("00000101");
    //cout << (bs^bs2).to_ullong() << endl;
    // 1の数が偶数回(0)でるか奇数回(1)かで値が変わる
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}