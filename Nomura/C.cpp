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
    vector<long> A(N+1);
    for(size_t i=0;i<=N; i++)
    {
        cin >> A[i];
        if(pow(2, i) < A[i] || (N>0 && A[0]>0))
        {
            cout << -1 << endl;
            return 0;
        }
    }
    ll total = 0;
    for(size_t i=0;i<=N; i++)
    {
        //cerr << pow(2, i) << endl;
        total += pow(2, i);
    }
    //cerr << total << endl;
    ll missing_leaf_total = 0;
    //cerr << A.size() << endl;
    /*
    for(size_t i=0;i<A.size(); i++)
    {
        ll missing_tree=0;
        //cerr << i << ":" << A[i] << endl;
        if(A[i] > 0)
        {
            //cerr << N - i << endl;
            for(size_t j=1;j<=N-i; j++)
            {
                missing_tree += j*2;
                cerr << i << ":" << A[i] << ":" << j * 2 << endl;
            }
        }
        missing_leaf_total += A[i]*missing_tree;
    }
    cout << total - missing_leaf_total << endl;
    */
    //葉からの枝は１本にした方が根が増える
    vector<ll> node(N+1);
    ll total_nodes = 0;
    for(ll i=A.size()-1;i>=0; i--)
    {
        
        if(i==A.size()-1) node[i]=A[i];
        else{
            if(int(pow(2, i)) >= node[i+1] + A[i])
            {
                //cerr << 2 * (int(pow(2, i-1)) -A[i-1]) << ":" << node[i+1] + A[i] << endl;
                if(2 * (int(pow(2, i-1)) -A[i-1]) >= node[i+1] + A[i]) node[i] = node[i+1] + A[i];
                else node[i] = 2 * (int(pow(2, i-1)) -A[i-1]);
            }
            else node[i] = int(pow(2, i));
        }
        total_nodes += node[i];
        //cerr << A[i] << ":" << int(pow(2, i)) << ":"<< node[i] << endl;
    }
    cout << total_nodes << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}