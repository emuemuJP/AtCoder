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
    string S,T;
    cin >> S >> T;
    // 回転の数
    for(size_t i=0;i<S.size(); i++)
    {
        bool ok = true;
        // 後ろから
        for(size_t j=0;j<i; j++)
        {
            cerr << S[S.size() - i + j] <<":" << T[j]<< endl;
            if(S[S.size() - i + j] != T[j])
            {
                ok=false;
                break;
            }
        }
        if(!ok)
        {
            continue;
            cerr << "b" << endl;
        }
        cerr << "mae" << endl;
        // 前から
        for(size_t j=i;j<S.size(); j++)
        {
            cerr << S[j - i] << ":" << T[j]<< endl;
            if(S[j - i] != T[j])
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}