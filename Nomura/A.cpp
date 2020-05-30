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
    long H_1, M_1, H_2, M_2, K;
    cin >> H_1 >> M_1 >> H_2 >> M_2 >> K;
    //if(M_2 < M_1) M_2+=60, H_2--;
    //ll minute = (H_2 - H_1) * 60 + (M_2 - M_1);
    //cerr << minute << endl;
    //cout << K * ((minute-1) / K) << endl;
    if(M_2 < K) M_2+=60,H_2--;
    M_2-=K;
    ll minute = (H_2 - H_1) * 60 + (M_2 - M_1);
    cout << minute << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}