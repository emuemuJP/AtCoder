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
    long N;
    cin >> N;
    string s1,s2;
    cin >> s1;
    cin >> s2;
    ll s1pos=0, s2pos=0;
    ll comb=1;
    bool prev_tate=false;
    while(s1pos!=s1.size() && s2pos!=s2.size())
    {
        //縦
        if(s1[s1pos]==s2[s2pos])
        {
            if(s1pos==0 && s2pos==0) comb*=3;
            else
            {
                if(prev_tate) comb*= 2;
                else comb*= 1 % DIV;
            }
            s1pos++;
            s2pos++;
            prev_tate = true;
        }
        //横
        else
        {
            if(s1pos==0 && s2pos==0) comb*=3*2;
            else
            {
                if(prev_tate) comb*=2;
                else comb*=3;
            }
            s1pos+=2;
            s2pos+=2;
            prev_tate = false;
        }
        comb%=DIV;
    }
    cout << comb << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}