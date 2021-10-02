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
#include <set>
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
    if(S==T)
    {
        cout << "Yes" << endl;
        return 0;
    }
    vector<ll> index;
    for(size_t i=0;i<S.size(); i++)
    {
        if(S[i]!=T[i])
        {
            index.push_back(i);
        }
    }
    if(index.size()!=2 || index[0]+1 != index[1]) cout << "No" << endl;
    else{
        if(S[index[0]]==T[index[1]] && S[index[1]]==T[index[0]]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}