#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pii;

#define GCD(x, y) __gcd(x, y)
#define LCM(x, y) (x * y) / __gcd(x, y)
#define N 1000001

int dp[N], trail[N];

int dynamic(int n) {
    if (dp[n] != -1) return dp[n];
    int ret = 987654321;
    if (n % 3 == 0 and ret > dynamic(n / 3)) {
        ret = dynamic(n / 3);
        trail[n] = n / 3;
    }
    if (n % 2 == 0 and ret > dynamic(n / 2)) {
        ret = dynamic(n / 2);
        trail[n] = n / 2;
    }
    if (ret > dynamic(n - 1)) {
        ret = dynamic(n - 1);
        trail[n] = n - 1;
    }
    return dp[n] = ret + 1;
}

void print(int n, int cnt) {j 
    if (cnt < 0) return;
    cout << n << ' ';
    print(trail[n], cnt - 1);
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    for (int i = 0; i < N; i++) dp[i] = -1;
    dp[1] = 0;
    int n;
    cin >> n;
    cout << dynamic(n) << '\n';
    print(n, dynamic(n));
    return 0;
}
