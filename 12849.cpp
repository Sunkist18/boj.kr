#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pii;

#define GCD(x, y) __gcd(x, y)
#define LCM(x, y) (x * y) / __gcd(x, y)
#define DIV 1000000007

int n;
vector<vector<int>> field = {{1, 2},
                              {0, 3},
                              {0, 3, 4},
                              {1, 2, 4, 5},
                              {2, 3, 5, 6},
                              {3, 4, 6, 7},
                              {4, 5, 7},
                              {5, 6}};
int dp[8];
int temp[8];

void solve() {
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < 8; i++)
        for (auto there : field[i])
            temp[i] += dp[there];
    for (int i = 0; i < 8; i++) dp[i] = temp[i] % DIV;
    return;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;    
    dp[7] = 1;
    while (n--) solve();
    cout << dp[7];
    return 0;
}
