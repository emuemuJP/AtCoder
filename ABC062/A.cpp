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
    long x, y;
    cin >> x >> y;
    if(x==2) cout << "No" << endl;
    else if(x == 4 || x == 6 || x == 9 || x==11)
    {
        if(y==6 || y==9 || y==11) cout << "Yes" << endl;
        else cout << "No" << endl;
    }else
    {
        if(y==3 || y==5 || y==7 || y==8 ||y==10 ||y==12) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}