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
#include <set>
#include <unordered_map>
#include <chrono>
#include <numeric>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18+1;
const ll DIV = 1000000007;
//#define TEST

//二つ整数のうち、一方を固定することで解をもとめる問題
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    ll N, M;
    cin >> N >> M;

    ll x,ans=INF;
    for(ll i=1;i<=N;i++){
        //mをiで割る際に、切り上げ（天井関数）を行って商を求めるためのものです。
		// x=(M+i-1)/i;
        x=ll(ceil(static_cast<double>(M)/i));
		if(x<=N) ans=min(ans,i*x);
		if(i>x) break;
	}
	if(ans==INF)cout<<-1<<endl;
	else cout<<ans<<endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}