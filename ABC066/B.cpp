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
    ll l = 0;
    cerr << S.size() << endl;
    for(int i=1;i<S.size(); i++)
    {
        cerr << S.substr(0, S.size()/2 -i) << ":" << S.substr(S.size()/2 -i, S.size()/2 -i) << endl;
        if(S.substr(0, S.size()/2 -i) == S.substr(S.size()/2 -i, S.size()/2 -i))
        {
            cerr << i << endl;
            l = (S.substr(0, S.size()/2 -i)).size()*2;
            break;
        }
    }
    cout << l << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}