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

/*
ll bfs(ll resN, const ll& nine, const ll& six, ll count, ll depth)
{
    bool isNine=false, isSix =false;
    if(depth > count) return count;
    for(size_t i=1;i<=nine; i++)
    {
        if(resN - pow(9, i) >= 0)
        {
            isNine = true;
            depth+=1;
            count = min(count, bfs(resN-pow(9, i), nine, six, count, depth));
        }

    }
    for(size_t i=1;i<=six; i++)
    {
        if(resN - pow(6, i) >= 0)
        {
            isSix=true;
            depth+=1;
            count = min(count, bfs(resN-pow(6, i), nine, six, count, depth));
        }
    }
    if(!isNine && !isSix)
    {
        count = depth + resN;
    }
    else{
        count = depth;
    }
    return count;
}
*/

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    long N;
    cin >> N;
    // 1
    //6, 6^2, 6^3, ...
    //9, 9^2, 9^3, ...
    //全探索
    // Nは最大でも 100,000
    //ll nine = 0;
    //while(pow(9, nine) < N) nine++;
    //cerr << nine-1 << ":" << pow(9, nine-1) << endl;
    // 9は５まで
    //ll six = 0;
    //while(pow(6, six) < N) six++;
    // 6は6まで
    //cerr << six-1 << ":" << pow(6, six-1)<< endl;
    ll count_max = N;
    //cout << bfs(N, nine, six, N, 0) << endl;
    for(int i=0; i<=N; i++)
    {
        int count=0;
        //6で割る数
        int t = i;
        //cerr << "i:" << i << endl;
        while(t > 0) count+= t%6, t/=6;
        //cerr << "\t:"<< count << endl;
        //9で割る数
        t=N-i;
        while(t > 0) count+= t%9, t/=9;
        if(count_max > count) count_max = count;
        //cerr << "\t:" << count_max << endl;
    }
    cout << count_max << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}