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
    long N,K;
    cin >> N >> K;
    string S;
    cin >> S;
    long opposite_counter=0;
    for(size_t i=0;i<N; i++)
    {
        if(S.substr(i, 2) == "LR" || S.substr(i, 2) == "RL")
        {
            opposite_counter++;
        }
    }

    if(opposite_counter <= K * 2) opposite_counter = 0;
    else opposite_counter -= K*2;
    
    cout << (N-1) - opposite_counter << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}