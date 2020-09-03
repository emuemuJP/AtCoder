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

bool inside(const int& i, const int& j, const long & H, const long & W, const vector<vector<char>>& mat){
    return (i >= 0 && i < H && j >= 0 && j < W && mat[i][j] == '.');
};


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    long H, W;
    cin >> H >> W;
    long Cx, Cy;
    cin >> Cy >> Cx;
    Cy--;Cx--;
    long Dx, Dy;
    cin >> Dy >> Dx;
    Dy--;Dx--;
    std::vector<std::vector<char>> mat(H, vector<char>(W));
    string S;
    for(size_t i=0;i<H; i++)
    {
        cin >> S;
        for(size_t j=0;j<S.size(); j++)
        {
            mat[i][j] = S[j];
        }
    }

    vector<vector<ll> > dist(H, vector<ll> (W, INF));
	dist[Cy][Cx] = 0;
	deque<pair<int, int>> que;
	que.push_front(pair<int, int>(Cy, Cx));
    while(que.size()){
	    pair<int, int> p = que.front(); que.pop_front();
		int y = p.first, x = p.second;
		for(int i = y - 2; i <= y + 2; i++){
			for(int j = x - 2; j <= x + 2; j++){
				if(!inside(i, j, H, W, mat)) continue;
				int adj = (abs(y - i) + abs(x - j) != 1);
				int d = dist[y][x] + adj;
				if(d < dist[i][j]){
					dist[i][j] = d;
                    if(adj) que.push_back(pair<long, long>(i, j));
					else que.push_front(pair<long, long>(i, j));
				}
			}
		}
	}

	ll ans = dist[Dy][Dx];
    if(ans == INF) ans = -1;
    cout << ans << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}