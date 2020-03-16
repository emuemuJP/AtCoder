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
using namespace std;
using ll = long long;
const long long INF = (long long)1e18+1;
#define DIV 1000000007
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    long idx=0;
    long N;
    cin >> N;
    long P;
    long count = 0;
    long min_num = INF;
    while(cin >> P)
    {
        if(min_num >= P)
        {
            count++;
        }
        min_num = min(min_num, P);
        idx++;
        if(N==idx) break;
    }

    cout << count << endl;
    return 0;
}