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

int COUNT = 0;
vector<string> S;

void reverse(int index, bool x, bool y)
{
    if(index >= 0)
    {
        //yがTrueでオペランドがAND
        if(y && S[index]=="AND")
        {
            reverse(index-1, 1, 1);
        }else if(!y && S[index]=="AND")
        {
            reverse(index-1, 1, 0);
            reverse(index-1, 0, 1);
            reverse(index-1, 0, 0);
        }else if(y && S[index]=="OR")
        {
            reverse(index-1, 0, 1);
            reverse(index-1, 1, 1);
            reverse(index-1, 1, 0);
        }else
        {
            reverse(index-1, 0, 0);
        }
    }else
    {
        COUNT+=1;
    }
    return;
}

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
    for(size_t i=0;i<N; i++)
    {
        string s;
        cin >> s;
        S.push_back(s);
    }
    /*
    for(ll b=0;b<(1<<(N+1)); b++)
    {
        ll cc = 0;
        bitset<61> x(b);
        //cerr << x << endl;
        bitset<1> ans(x[N]);
        //cerr << ans << endl;
        for(int i=N-1;i>=0; i--)
        {
            if(S[N-1-i]=="AND") ans[0] = ans[0]&x[i];
            else ans[0] = ans[0]|x[i];
        }
        if(ans[0]==1) count++;
        //cerr << y[0]  << ":" << count << endl;
    }
    */
    reverse(N-1, 0, 1);
    cout << COUNT << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}