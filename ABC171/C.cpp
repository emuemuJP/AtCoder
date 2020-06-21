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
    ll Nmax = 1000000000000001;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    ll pre = 0;
    ll countable = 0;
    ll len = 1;
    while(countable < N)
    {
        pre = countable;
        countable += pow(26, len);
        //cerr << countable << endl;
        len++;
    }
    //cerr << len-1 << ":" << pre+1  << ":" << countable - pre << endl;
    ll length = len-1;
    ll namable = N - pre - 1;
    //cerr << namable << ":" << length << endl;
    vector<ll> name(length);
    for(ll i=length-1;i>=0; i--)
    {
        if(i!=0)
        {
            name[i] = namable / pow(26, i);
            namable -= pow(26, i) * name[i];
        }
        else
        {
            name[i] = namable;
        }
    }
    for(ll i=length-1;i>=0; i--)
    {
        //cerr << name[i];
        cout << alphabet[name[i]];
    }
    //cerr << endl;
    cout << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}