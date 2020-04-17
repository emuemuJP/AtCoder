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
const long long INF = (long long)1e18+1;
#define DIV 1000000007
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    long idx=0;
    long N, K;
    cin >> N >> K;
    long R, S, P;
    cin >> R >> S >> P;
    string T;
    cin >> T;
    // R S P の数
    map<long,bool> R_index;
    map<long,bool> S_index;
    map<long,bool> P_index;
    for(size_t i=0;i<N; i++)
    {
        if(T[i] == 'r')
        {
            if(i-K >= 0 && R_index[i-K]) continue;
            R_index[i] = true;
        }
        else if(T[i] == 's')
        {
            if(i-K >= 0 && S_index[i-K]) continue;
            S_index[i] = true;
        }
        else
        {
            if(i-K >= 0 && P_index[i-K]) continue;
            P_index[i] = true;
        }
    }
    long R_count=0;
    for (const auto& elem : R_index){
        //cerr << "R:" << elem.first << ":" << elem.second << endl;
        if(elem.second) R_count++;
    }
    long S_count=0;
    for (const auto& elem : S_index){
        //cerr << "S:" << elem.first << ":" << elem.second << endl;
        if(elem.second) S_count++;
    }
    long P_count=0;
    for (const auto& elem : P_index){
        //cerr << "P:" << elem.first << ":" << elem.second << endl;
        if(elem.second) P_count++;
    }
    cout << R_count * P + S_count * R + P_count * S << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}