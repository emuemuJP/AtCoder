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
    int N;
    string S;
    cin >> N >> S;
    bool ok = true;
    char next;
    if (S[0] == 'F') next = 'S';
    else next = 'F';
    for (size_t i = 1; i < N; i++)
    {
        if(S[i]==next)
        {
            if (S[i] == 'F') next = 'S';
            else next = 'F';
        }
        else break;
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}