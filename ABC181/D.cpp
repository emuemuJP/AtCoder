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
    string S;
    cin >> S;
    map<int, int> s;
    for(size_t i=0;i<S.size(); i++)
    {
        s[(S[i]-'0')]++;
    }
    //bool ok = false;
    // 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104,...
    // 0, 2, 4, 6, 8
    /*
    for(size_t i=pow(10, S.size()-1);i<pow(10, S.size()); i++)
    {
        if(i % 10 == 0) continue;
        if(i % 8 == 0)
        {
            //cerr << i << endl;
            string T = to_string(i);
            map<int, int> t;
            for(size_t j=0;j<T.size(); j++)
            {
                t[(T[j]-'0')]++;
            }
            if(s == t)
            {
                ok = true;
                break;
            }
        }
    }
    */
   bool ok = true;
    for(size_t i=1;i<1000; i++)
    {
        if((i % 8) == 0)
        {
            string T = to_string(i);
            if(S.size()< 3)
            {
                if(S.size() != T.size()) continue;
            }
            else
            {
                if(T.size() < 3) continue;
            }
            map<int, int> t;
            for(size_t j=0;j<T.size(); j++)
            {
                t[(T[j]-'0')]++;
            }
            ok = true;
            //cerr << i << endl;

            for(auto e:t)
            {
                //cerr << e.first << e.second << endl;
                if(e.second > s[e.first])
                {
                    ok = false;
                    break;
                }
            }
            if(ok) break;
        }
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}