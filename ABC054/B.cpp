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
    std::vector<std::vector<char>> A(N, vector<char>(N, ' '));
    std::vector<std::vector<char>> B(M, vector<char>(M, ' '));
    for(size_t i=0;i<N; i++)
    {
        string l;
        cin >> l;
        for(size_t j=0;j<l.size(); j++)
        {
            A[i][j] = l[j];
        }
    }
    for(size_t i=0;i<M; i++)
    {
        string l;
        cin >> l;
        for(size_t j=0;j<l.size(); j++)
        {
            B[i][j] = l[j];
        }
    }
    bool _ok = false;
    for(size_t i=0;i<=N-M; i++)
    {
        for(size_t j=0;j<=N-M; j++)
        {
            bool ok = true;
            for(size_t ii=0;ii<M; ii++)
            {
                for(size_t jj=0;jj<M; jj++)
                {
                    if(A[i+ii][j+jj]!=B[ii][jj])
                    {
                        ok=false;
                        break;
                    }
                }
                if(!ok) break;
            }
            _ok = ok;
            if(_ok) break;
        }
        if(_ok) break;
    }
    if(_ok) cout << "Yes" << endl;
    else cout << "No" << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}