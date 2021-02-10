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
    string a,b,c;
    cin >> a >> b >> c;
    ll count_a=0, count_b=0, count_c=0;
    char s = a[count_a];
    count_a++;
    //cerr << a.size() << b.size() << c.size() << endl;
    while(count_a<=a.size() && count_b<=b.size() && count_c<=c.size())
    {
        if(s=='a')
        {
            s = a[count_a];
            count_a++;
        }else if(s=='b')
        {
            s = b[count_b];
            count_b++;
        }else
        {
            s = c[count_c];
            count_c++;
        }
        //cerr << s << endl;
    }
    if(count_a>a.size()) cout << "A" << endl;
    else if(count_b>b.size()) cout << "B" << endl;
    else
    {
        //assert(count_c<c.size());
        cout << "C" << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}