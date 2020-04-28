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
    string S;
    cin >> S;
    string subS_front = S.substr(0, (S.size()-1)/2);
    string subS_back = S.substr((S.size()+3)/2-1);
    //cout << subS_front << ":" << subS_back << endl;
    string reverseS = S, reverse_subS_front = subS_front, reverse_subS_back = subS_back;
    reverse(reverseS.begin(), reverseS.end());
    reverse(reverse_subS_front.begin(), reverse_subS_front.end());
    reverse(reverse_subS_back.begin(), reverse_subS_back.end());
    if(S == reverseS && subS_front == reverse_subS_front && subS_back == reverse_subS_back)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}