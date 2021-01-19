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
    string s;
    cin >> s;
    int apos = 0, zpos = 0;
    for(size_t i=0;i<s.size(); i++)
    {
        if(s[i]=='A')
        {
            apos = i;
            break;
        }
    }
    for(int i=s.size()-1;i>=0; i--)
    {
        if(s[i] == 'Z')
        {
            zpos = i;
            break;
        }
    }
    cout << zpos - apos + 1 << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}