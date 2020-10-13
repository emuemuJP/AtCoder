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
    long X;
    cin >> X;
    //2^10以下33^2
    long num = sqrt(X);
    ll max_num=0;
    for(int i=num;i>=1;i--)
    {
        for(int p=2;p<10;p++)
        {
            ll pow_num= pow(i, p);
            if(pow_num <= X)
            {
                if(max_num < pow_num) max_num = pow_num;
            }
            else break;
        }
    }
    cout << max_num << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}