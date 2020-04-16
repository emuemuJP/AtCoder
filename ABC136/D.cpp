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
    string S;
    cin >> S;
    // R *** L
    // R Lで往復する
    // Rの連続の移動とLの連続の移動は RL が現れるまで続く
    //Rにより RL に到達した数とLにより RL に到達した数を数える
    vector<long> Rpos(S.size());
    long Rcount=0;
    for(size_t i=0;i<S.size(); i++)
    {
        if(S[i] == 'R') Rcount++;
        else Rcount = 0;
        if(S.substr(i, 2) == "RL")
        {
            Rpos[i]  =  Rcount / 2 + Rcount % 2;
            Rpos[i+1] = Rcount / 2;
        }
    }
    vector<long> Lpos(S.size());
    long Lcount=0;
    for(size_t i=S.size()-1;i>0; i--)
    {
        if(S[i] == 'L') Lcount++;
        else Lcount = 0;
        if(S.substr(i-1, 2) == "RL")
        {
            Lpos[i-1]  = Lcount / 2;
            Lpos[i]    = Lcount / 2 + Lcount % 2;
        }
    }
    for(size_t i=0;i<S.size(); i++)
    {
        cout << Rpos[i] + Lpos[i] << " ";
    }
    cout << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}