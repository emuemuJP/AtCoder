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
    long a, b;
    cin >> a >> b;
    if(a >= b)
    {
        for(size_t i=0;i<a; i++)
        {
            cout << b;
        }
        cout << endl;
    }
    else
    {
        for(size_t i=0;i<b; i++)
        {
            cout << a;
        }
        cout << endl;
    }
    return 0;
}
