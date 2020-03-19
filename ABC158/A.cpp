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
using namespace std;
using ll = long long;
const long long INF = (long long)1e18+1;
#define DIV 1000000007
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    long idx=0;
    string S;
    cin >> S;
    bool isBus = false;
    for(size_t i = 1;i<S.size(); i++)
    {
        if(S[0] != S[i]) isBus = true;
    }
    if(isBus) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}