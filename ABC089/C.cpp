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
    map<char, ll> S;
    for(size_t i=0;i<N; i++)
    {
        string s;
        cin >> s;
        if(s[0]=='M'||s[0]=='A'||s[0]=='R'||s[0]=='C'||s[0]=='H')
            S[s[0]]++;
    }
    //cerr <<S.size()<< endl;
    //for(auto s : S) cerr <<s.first << ":" << s.second << endl;
    ll comb=0;
    if(S.size()<3)
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {
        cerr << S.size() << endl;
        ll Ssize = S.size();
        vector<char> march={'M', 'A', 'R', 'C', 'H'};
        for(ll i=0;i<march.size(); i++)
        {
            for(ll j=i+1;j<march.size(); j++)
            {
                for(ll k=j+1;k<march.size(); k++)
                {
                    //cerr << march[i] << "," << march[j] << "," << march[k] << endl;
                    //cerr << S[march[i]] << "," << S[march[j]] << "," << S[march[k]] << endl;
                    comb+=S[march[i]]*S[march[j]]*S[march[k]];
                }
            }
        }
    }
    cout << comb << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}