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

template<class T> bool chmax(T& a, const T b){
    bool isMax = false;
    if(a < b){
        a=b;
        isMax = true;
    }
    return isMax;
}

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
    
    // map<ll, int> num;
    // for(size_t i=0;i<N.size(); i++)
    // {
    //     num[(N[i]-'0')]++;
    // }
    // cerr << num.size() << endl;
    // for(auto a:num) cerr << a.first << ":" << a.second << endl;
    ll max_num=0;
    //区切り方を決めたら、分離された中の最大数を考えれば良い
    for(ll bit=0;bit< (1<<N.size())-1; bit++)
    {
        bitset<10> bits(bit);
        bitset<10> _bits = bits^bitset<10>("1111111111");
        //cerr << bits << ":" << _bits << endl;
        vector<ll>lhs,rhs;
        for(size_t i=0;i<N.size(); i++)
        {
            if(bits[i]) lhs.push_back(N[i]-'0');
            if(_bits[i]) rhs.push_back(N[i]-'0');
        }
        sort(lhs.begin(), lhs.end());
        sort(rhs.begin(), rhs.end());
        ll lhs_num=0, rhs_num=0;
        for(int i=0;i<lhs.size();i++) lhs_num += lhs[i] * pow(10, i);
        for(int i=0;i<rhs.size();i++) rhs_num += rhs[i] * pow(10, i);
        chmax(max_num, lhs_num*rhs_num);
    }
    cout << max_num << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}