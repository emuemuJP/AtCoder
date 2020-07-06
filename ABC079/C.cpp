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
    long ABCD;
    cin >> ABCD;
    long A,B,C,D;
    A = ABCD / 1000;
    B = ABCD / 100 % 10;
    C = ABCD / 10 % 10;
    D = ABCD % 10;
    ll result, i, j, k;
    cerr << A << B << C << D << endl;
    bool isSeven = false;
    for(i=0;i<=1; i++)
    {
        for(j=0;j<=1; j++)
        {
            for(k=0;k<=1; k++)
            {
                if(i==0) result = A+B;
                if(i==1) result = A-B;
                if(j==0) result +=C;
                if(j==1) result -=C;
                if(k==0) result +=D;
                if(k==1) result -=D;

                if(result == 7)
                {
                    isSeven= true;
                    break;
                }
            }
            if(isSeven) break;
        }
        if(isSeven) break;
    }
    cerr << i << j << k << endl;
    string pm = "+-";
    cout << A << pm[i] << B << pm[j] << C << pm[k] << D << "=7" << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}