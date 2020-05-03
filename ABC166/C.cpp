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
    long N, M;
    cin >> N >> M;
    vector<ll> H(N);
    for(size_t i=0;i<N; i++)
    {
        cin >> H[i];
    }
    map<long, vector<long>> H_path;
    long A, B;
    for(size_t i=0;i<M; i++)
    {
        cin >> A >> B;
        H_path[A].push_back(B);
        H_path[B].push_back(A);
    }
    ll count = 0;
    for(const auto& h:H_path)
    {
        bool isOK = true;
        //cerr << h.first << ":" << H[h.first-1] << ":<pair>:";
        for(size_t i=0;i<h.second.size(); i++)
        {
            if(H[h.first-1] <= H[h.second[i]-1])
            {
                isOK=false;
                break;
            }
            //cerr << h.second[i] << " ";
        }
        if(isOK) count++;
        //cerr << endl;
    }
    cout << count + (N - H_path.size()) << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}