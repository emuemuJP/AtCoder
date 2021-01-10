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
#include <sstream>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18+1;
const ll DIV = 1000000007;
//#define TEST
template <typename T> T from_string(std::string const & s) {
    std::stringstream ss(s);
        T result;
        ss >> result;
        return result;
}
//template ll from_string(std::string const & s);
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    string N;
    cin >> N;
    //bitset<18> del;
    ll min_del = INF;
    bool ok = false;

    //bitの組み合わせを列挙
    for(ll bit=0;bit< (1<<N.size())-1; bit++)
    {
        bitset<18> bits(bit);
        //cerr << bits << endl;
        string del_n="0";
        for(int i=0;i<N.size(); i++)
        {
            if(!bits[i]) del_n += N[i];
        }
        //STUCK: stoll didn't work.
        //cerr << from_string<ll>(del_n) << endl;
        if(from_string<ll>(del_n) % 3 == 0)
        {
            cerr << from_string<ll>(del_n) << endl;
            ok = true;
            min_del = min(min_del, ll(bits.count()));
        }
    }

    if(ok) cout << min_del << endl;
    else cout << "-1" << endl;

#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}