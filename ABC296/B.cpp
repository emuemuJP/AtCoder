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
    vector<string> S(8);
    for(size_t i=0;i<8; i++)
    {
        cin >> S[i];
    }
    string alpha[8] = {"a", "b", "c", "d", "e", "f", "g", "h"};
    for(size_t i=0;i<8; i++)
    {
        for(size_t j=0;j<8; j++)
        {
            if(S[i][j] == '*') cout << alpha[j] << 8-i << endl;
        }
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}