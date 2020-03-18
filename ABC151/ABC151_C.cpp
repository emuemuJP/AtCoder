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
    long N, M;
    cin >> N >> M;
    // 問題番号の正解数、不正解数を記録する必要
    std::vector<pair<long, long>> mat(N, pair<long, long>(0, 0));
    long num;
    string ans;

    for(size_t i = 0; i < M; i++)
    {
        cin >> num >> ans;
        pair<long, long> current_state = mat[num-1];
        //cerr << "pre:" << current_state.first << ":" << current_state.second << endl;
        if(ans == "AC")
        {
            if(current_state.first == 1) continue;
            mat[num-1] = make_pair(1, current_state.second);
        }
        else
        {
            if(current_state.first == 1) continue;
            mat[num-1] = make_pair(0, current_state.second + 1);
        }
        //cerr << "post:" << mat[num-1].first << ":" << mat[num-1].second << endl;
    }
    long correct = 0, wrong = 0;
    for(size_t i = 0; i< N; i++)
    {
        correct += mat[i].first;
        if(mat[i].first == 1)
            wrong += mat[i].second;
    }
    cout << correct << " " << wrong << endl;
    return 0;
}