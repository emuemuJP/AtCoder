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
    long N;
    string S;
    cin >> N;
    cin >> S;
    char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G' ,'H', 'I',
                        'J', 'K', 'L', 'M', 'N', 'O', 'P' ,'Q', 'R',
                        'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    for(size_t i=0;i<S.size(); i++)
    {
        for(size_t a=0;a<26; a++)
        {
            if(S[i] == alphabet[a])
            {
                if(a + N >= 26) cout << alphabet[a+N-26];
                else cout << alphabet[a+N];
            }
        }
    }
    cout << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << '[ms]' << endl;
#endif
    return 0;
}