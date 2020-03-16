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

pair<long, long> calcDigit(int n) {
 
	pair<long, long> num;
	num.first = n % 10;
	while (n / 10) {
		n /= 10;
	}
	num.second = n;
	return num;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    long idx=0;
    long N;
    cin >> N;
    long count = 0;
    std::vector<std::vector<int>> mat(15, vector<int>(15, 0));
    // A の末尾の桁が B の先頭の桁に等しく、A の先端の桁が B の末尾の桁に等しい
    // 先端と末尾だけ考えればいい
    for (int i = 1; i <= N; i++)
	{
		int head = 0;
		int tail = 0;
		tie(tail, head) = calcDigit(i);
        mat[head][tail]++;
	}
    
    int ans = 0;
	for (int i = 0; i <= 9; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			count += mat[i][j] * mat[j][i];
		}
	}
 
    cout << count << endl;
    return 0;
}