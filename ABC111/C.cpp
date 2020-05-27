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

using ipair = pair<ll,ll>;
bool operator>(const ipair a,const ipair b){return a.second > b.second;};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    ll n;
    cin >> n;
    vector<ll> v(n);
    map<ll, ll> odd;
    map<ll, ll> even;
    for(size_t i=0;i<n; i++)
    {
        cin >> v[i];
        if( (i+1) % 2 != 0) odd[v[i]]++;
        else even[v[i]]++;
    }
    //for(auto i : odd) cerr << "odd:" << i.first << ":" << i.second << endl;
    //for(auto i : even) cerr << "even:" << i.first << ":" << i.second << endl;
    //cerr << "size:" << odd.size() << ":" << even.size() << endl;

    vector<pair<ll, ll>> a, b;
    for (auto o : odd) a.emplace_back(o.second, o.first);
	for (auto e : even) b.emplace_back(e.second, e.first);
	//cerr << "size:" << a.size() << ":" << b.size() << endl;
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    //for(auto i : a) cerr << i.first << ":" << i.second << endl;
    //for(auto i : b) cerr << i.first << ":" << i.second << endl;

    if (a.front().second == b.front().second) {
		int ans = a.front().first;
		if (a.size() == 1 && b.size() == 1) {
			cout << n / 2 << endl;
			return 0;
		}
        ll index_a = 0, index_b = 0;
        if(a.size()>1)  index_a++;
        if(b.size()>1)  index_b++;
		if(index_a == index_b)
        {
            if (a[index_a].first >= b[index_b].first) {
                ans += a[index_a].first;
            }
            else {
                ans += b[index_b].first;
            }
            cout << n - ans << endl;
        }else
        {
            if(index_a > index_b)
                ans += a[index_a].first;
            else
                ans += b[index_b].first;
            cout << n - ans << endl;

        }
	}
	else {
        cout << n - a.front().first - b.front().first << endl;
	}
	return 0;
    /*
    priority_queue<ipair,vector<ipair>,greater<ipair>> odd_que;
    priority_queue<ipair,vector<ipair>,greater<ipair>> even_que;
    for(const auto& o:odd)
    {
        odd_que.push(make_pair(o.first, o.second));
    }
    for(const auto& e:even)
    {
        even_que.push(make_pair(e.first, e.second));
    }

    if (odd_que.top().second == even_que.top().second) {
		int ans = odd_que.top().first;
		if (odd_que.size() == 1 && even_que.size() == 1) {
			cout << n / 2 << endl;
			return 0;
		}
        odd_que.pop();even_que.pop();
        ipair second_odd;
        ipair second_even;
        if(!odd_que.empty()) second_odd = odd_que.top();odd_que.pop();
        if(!even_que.empty()) second_even = even_que.top();even_que.pop();
		if (second_odd.second >= second_even.second) {
			ans += second_odd.second;
		}
		else {
			ans += second_even.second;
		}
		cout << n - ans << endl;
	}
	else {
		int ans = odd_que.top().first + even_que.top().first;
		cout << n - ans << endl;
	}
	return 0;
    
    ipair _odd = odd_que.top();odd_que.pop();
    ipair _even = even_que.top();even_que.pop();
    cerr << _odd.first << ":" << _odd.second << endl;

    //最初のkeyが異なる
    if(_odd.first != _even.first)
    {
        cout << (n/2 - _odd.second) + (n/2 - _even.second) << endl;
    }
    else //最初keyが同じ
    {
        if(even.size() == 1 && odd.size() == 1) cout << n/2 << endl;
        else
        {
            ipair second_odd = _odd;
            ipair second_even = _even;
            if(!odd_que.empty()) second_odd = odd_que.top();odd_que.pop();
            if(!even_que.empty()) second_even = even_que.top();even_que.pop();
            //次のキーが同じかどうかは関係ない
            if(odd.size() == 1) cout << n/2 - second_even.second << endl;
            else if(even.size() == 1) cout << n/2 - second_odd.second << endl;
            else
            {
                //cout << min((n/2 - second_even.second) + (n/2 - _odd.second),
                //            (n/2 - second_odd.second) + (n/2 - _even.second)) << endl;
                //二つ目のkeyの数が多い方に合わせる
                if(second_odd.second > second_even.second) cout << (n/2 - second_odd.second) + (n/2 - _even.second) << endl;
                //else cout << (n/2 - second_even.second) + (n/2 - _odd.second)<< endl;
            }
        }
    }
    */
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}