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
    cin >> N;
    ll count = 0;
    ll digit = to_string(N).size();
    std::vector<std::vector<ll>> origin(11, vector<ll>());
    origin[1] = {3, 5, 7};
    vector<ll> elem = {3, 5, 7};
    ll isDone = false;
    for(size_t dig=1;dig<=9; dig++)
    {
        for(const auto& org:origin[dig])
        {
            for(const auto& e:elem)
            {
                ll candidate =  org * 10 + e;
                origin[dig+1].push_back(candidate);
                if(N >= candidate)
                {
                    string _candidate = to_string(candidate);
                    bool isThree = false;
                    bool isFive = false;
                    bool isSeven = false;
                    for(const auto& c:_candidate)
                    {
                        if(c == '3') isThree = true;
                        if(c == '5') isFive = true;
                        if(c == '7') isSeven = true;
                        if(isThree && isFive && isSeven)
                        {
                            count++;
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << count << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}