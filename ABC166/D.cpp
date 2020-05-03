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
    long X;
    // X は正の整数
    cin >> X;

    //A, Bの組で作れる値は限られている
    const int max_num = 200;
    vector<ll> elem(max_num);
    for(size_t i=0;i<=max_num; i++)
    {
        elem[i] = pow(i, 5);
    }
    //Aループ+
    for(int i=0;i<=max_num; i++)
    {
        //Bループ+
        for(int j=0;j<=max_num; j++)
        {
            if(elem[i] - elem[j] == X)
            {
                cout << i << " " << j << endl;
                return 0;
            }
        }
        //Bループ-
        for(int j=0;j<=max_num; j++)
        {
            if(elem[i] + elem[j] == X)
            {
                cout << i << " " << -j << endl;
                return 0;
            }
        }
    }
    //Aループ-
    for(int i=0;i<=max_num; i++)
    {
        //Bループ+
        for(int j=0;j<=max_num; j++)
        {
            if(-elem[i] - elem[j] == X)
            {
                cout << -i << " " << j << endl;
                return 0;
            }
        }
        //Bループ-
        for(int j=0;j<=max_num; j++)
        {
            if(-elem[i] + elem[j] == X)
            {
                cout << -i << " " << -j << endl;
                return 0;
            }
        }
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}