#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pii;

#define GCD(x, y) __gcd(x, y)
#define LCM(x, y) (x * y) / __gcd(x, y)

int n, m;

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    vector<vector<int>> field(n, vector<int>(n));
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> field[i][j];
            dp[i][j] = field[i][j];
            if (i != 0) dp[i][j] += dp[i - 1][j];
            if (j != 0) dp[i][j] += dp[i][j - 1];
            if (i != 0 and j != 0) dp[i][j] -= dp[i - 1][j - 1];
        }
    }

    int x1, y1, x2, y2;
    for (int i = 0; i < m; i++) {
        cin >> y1 >> x1 >> y2 >> x2;
        x1--; x2--; y1--; y2--;
        int result = dp[y2][x2];
        if (x1 > 0 and y1 > 0) result += dp[y1 - 1][x1 - 1];
        if (x1 > 0) result -= dp[y2][x1 - 1];
        if (y1 > 0) result -= dp[y1 - 1][x2];
        cout << result << '\n';
    }
    return 0;
}
