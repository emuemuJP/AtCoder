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
const long long INF = (long long)1e18+1;
#define DIV 1000000007


long honest_people(long N, std::vector<std::vector<pair<long, bool>>> mat, long i)
{
    bool contradiction = false;
    // 0:不親切 1:正直 2:不明
    std::vector<int> people(N, 2);
    people[i] = 1;
    queue<int> honest;
    honest.push(i);
    cerr << i << endl;
    while(!honest.empty() && !contradiction)
    {
        int now = honest.front();honest.pop();
        for(size_t j=0;j<mat[now].size(); j++)
        {
            if(people[mat[now][j].first] == 2)
            {
                people[mat[now][j].first] = mat[now][j].second;
                if(mat[now][j].second) honest.push(mat[now][j].first);
            }
            else
            {
                if(people[mat[now][j].first] != mat[now][j].second)
                {
                    contradiction = true;
                    break;
                }
            }

        }
    }
    if(contradiction) return 0;
    long count = 0;
    for(size_t i=0;i<N; i++)
    {
        cerr << "\t" << i << ":" << people[i] << endl;
        if(people[i] == 1) count++;
    }
    return count;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    long idx=0;
    long N;
    cin >> N;
    std::vector<std::vector<pair<long, bool>>> mat(N, vector<pair<long, bool>>());
    long A;
    for(size_t i=0;i<N; i++)
    {
        cin >> A;
        vector<pair<long, bool>> testimony(A);
        long x;bool y;
        for(size_t j=0;j<A; j++)
        {
            cin >> x >> y;
            testimony[j] = make_pair(x-1, y);
        }
        mat[i] = testimony;
    }
    long max_honest=0;
    // 一人づつ正直ものであるという仮定を置く
    // 証言に矛盾が出たら打ち切り
    // 矛盾が出なければok
    for(size_t i=0;i<N; i++)
    {
        max_honest = max(max_honest, honest_people(N, mat, i));
    }
    cout << max_honest << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}