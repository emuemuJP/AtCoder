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
    long N;
    cin >> N;
    string S;
    cin >> S;
    ll total = 0;
    vector<long> R;
    vector<long> G;
    vector<long> B;
    for(size_t i=0;i<N; i++)
    {
        if(S[i] == 'R') R.push_back(i);
        else if(S[i] == 'G') G.push_back(i);
        else if(S[i] == 'B') B.push_back(i);
    }
    ll out_of_rule = 0;
    for(size_t i=0;i<R.size(); i++)
    {
        for(size_t j=0;j<G.size(); j++)
        {
            ll index = abs(R[i] - G[j]);
            //cerr << R[i] << "," << G[j] << ":" << index << endl;
            if(index % 2 == 0 && S[min(R[i], G[j]) + index/2] == 'B') out_of_rule++;
            if(max(R[i], G[j]) + index < N && S[max(R[i], G[j]) + index] == 'B') out_of_rule++;
            if(min(R[i], G[j]) - index >= 0 && S[min(R[i], G[j]) - index] == 'B') out_of_rule++;
        }
    }
    cout << R.size()*G.size()*B.size() - out_of_rule << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}