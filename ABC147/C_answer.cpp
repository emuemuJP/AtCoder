#include <iostream>
using namespace std;

int N;
int A[20];
int x[20][20];
int y[20][20];

int counter(int x) {
    if(x == 0) return 0;
    return counter(x >> 1) + (x & 1);
}

void solve() {
    int ans = 0;
    // 人数分 bit を立てる
    // 人数分の真偽パターン
    for(int bits = 1; bits < (1 << N); bits++) {
        bool ok = true;
        //cerr << bits << endl;
        for(int i = 1; i <= N; i++) {
            // i-1 はbitshift数を表す
            // 1 を 0 bitshiftすると 1 001
            // 1 を 1 bitshiftすると 2 010
            // 1 を 2 bitshiftすると 4 110
            // & は両方が1のときのみ1とする
            if(!(bits & (1 << (i-1)))) continue;
            // 真実を証言している場合のみ検証
            for(int j = 1; j <= A[i]; j++) {
                // ^ : XOR
                // 右bitシフトしている
                // bitですでにその人が真か偽か仮定しているのでそれと反して(XOR)いたら矛盾
                //cerr << "\t" << i << "," << j  << ":" << (bits >> (x[i][j]-1)) << endl;
                if(((bits >> (x[i][j]-1)) & 1) ^ y[i][j]) ok = false;
            }
        }
        if(ok) ans = max(ans, counter(bits));
    }
    cout << ans << endl;
    return;
}

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        for(int j = 1; j <= A[i]; j++) {
            cin >> x[i][j] >> y[i][j];
        }
    }
    solve();
    return 0;
}
