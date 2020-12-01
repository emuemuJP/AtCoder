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
    bool ok=true;
    if(S[0]=='A')
    {
        ll Ccount=0;
        for(size_t i=1;i<S.size(); i++)
        {
            if(i>=2 && i<=S.size()-2)
            {
                if(S[i]=='C') Ccount++;
                else
                {
                    if(int(S[i]) <= 90) ok=false;
                }
            }else
            {
                if(int(S[i]) <= 90) ok=false;
            }
        }
        if(Ccount==0 || Ccount>=2) ok=false;
    }else ok = false;

    if(ok) cout << "AC" << endl;
    else cout << "WA" << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}