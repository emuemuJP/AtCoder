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
    string S_,T;
    cin >> S_ >> T;
    bool ok=false;
    ll key = 0;
    for(ll i=0;i<=ll(S_.size())-ll(T.size());i++)
    {
        ll cnt=0;
        for(ll j=0;j<T.size();j++)
        {
            if(S_[i+j]=='?'||S_[i+j]== T[j]) cnt++;
        }
        if(cnt==T.size())
        {
            key = i;
            ok=true;
        }
    }
    if(ok)
    {
        string ans="";
        for(ll i=0;i<S_.size(); i++)
        {
            if(i==key)
            {
                i+=T.size()-1;
                ans += T;
            }else
            {
                if(S_[i]=='?') ans += 'a';
                else ans += S_[i];
            }
        }
        cout << ans << endl;
    }else
    {
        cout << "UNRESTORABLE" << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}