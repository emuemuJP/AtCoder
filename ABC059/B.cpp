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
    string A, B;
    cin >> A >> B;
    if(A.size() > B.size()) cout << "GREATER" << endl;
    else if(B.size() > A.size()) cout << "LESS" << endl;
    else
    {
        int gle = -1;
        for(size_t i=0;i<A.size(); i++)
        {
            if(A[i] > B[i])
            {
                gle = 0;
                break;
            }
            else if(B[i] > A[i])
            {
                gle = 1;
                break;
            }
        }
        if(gle==-1) cout << "EQUAL" << endl;
        else if(gle==0) cout << "GREATER" << endl;
        else cout << "LESS" << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}