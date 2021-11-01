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
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    struct Train{
        ll number;
        Train* top;
        Train* front;
        Train* back;
    };
    ll N, Q;
    cin >> N >> Q;
    vector<Train*> Trains(N);
    for(ll i=0;i<N; i++)
    {
        Trains[i] = new Train{i+1, NULL, NULL, NULL};
    }
    for(size_t i=0;i<Q; i++)
    {
        ll order;
        cin >> order;
        if(order != 3)
        {
            int x, y;
            cin >> x >> y;
            if(order == 1) //unite
            {
                Trains[x-1]->back = Trains[y-1];
                Trains[y-1]->front = Trains[x-1];
                Trains[y-1]->top = Trains[x-1];
            }
            else{ //devide
                Trains[x-1]->back = NULL;
                Trains[y-1]->front = NULL;
                Trains[y-1]->top = NULL;
            }
        }else{
            int x;
            cin >> x;
            Train* current_train;
            if(Trains[x-1]->top!=NULL) current_train = Trains[x-1]->top;
            else current_train = Trains[x-1];
            while(current_train->top != NULL) current_train = current_train->top;
            vector<ll> nums;
            while(current_train->back != NULL)
            {
                nums.push_back(current_train->number);
                current_train = current_train->back;
            }
            nums.push_back(current_train->number);
            cout << nums.size() << " ";
            for(size_t n=0;n<nums.size()-1; n++)
            {
                cout << nums[n] << " ";
            }
            cout << nums[nums.size()-1] << endl;
        }
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}