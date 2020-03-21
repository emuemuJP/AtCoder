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
    string S;
    cin >> S;
    long Q;
    cin >> Q;
    long T, F;
    char C;
    long reverse_count = 0;
    //string head, tail;
    deque<char> ans;
    for(int i = 0; i < S.size(); i ++)
    {
        char c = S[i];
        ans.push_back(c);
    }
    for(size_t i=0;i<Q;i++)
    {
        cin >> T;

        if(T == 1) reverse_count++;
        else
        {
            //cerr << "反転" << reverse_count << endl;
            cin >> F >> C;
            //反転状態の場合は逆になる
            if(reverse_count % 2 == 0)
            {
                if(F == 1) ans.push_front(C);//head= C + head;
                else ans.push_back(C);//tail+=C;
            }else
            {
                if(F == 1) ans.push_back(C);//head=C + head;
                else ans.push_front(C);//tail+=C;
            }
        }
        //cerr << S << endl;
    }
    //S = head + S + tail;
    if(reverse_count % 2 == 0)
    {
        for(auto itr = ans.begin(); itr != ans.end(); ++itr) {
            cout << *itr;
        }
        cout << endl;
    }else
    {
        //cerr << "最後に反転" << endl;
        //reverse(ans.begin(), ans.end());
        for(auto itr = ans.rbegin(); itr != ans.rend(); ++itr) {
            cout << *itr;
        }
        cout << endl;
    }
    //cout << ans << endl;
    return 0;
}