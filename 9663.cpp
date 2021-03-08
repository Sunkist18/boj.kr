#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pii;

#define GCD(x, y) __gcd(x, y)
#define LCM(x, y) (x * y) / __gcd(x, y)

int n;
int prev_x[15]; 

bool promise_chess(int x, int layers) {
    for (int layer = 0; layer < layers; layer++) {
        if (x == prev_x[layer] || abs(prev_x[layer] - x) == abs(layers - layer))
            return false;
    }
    return true;
}

// x, y 에 착수하겠다.
int solve(int x, int layer) {
    // 착수 가능 여부 확인
    if (!promise_chess(x, layer)) return 0;
    // 마지막 레이어에 도착
    if (layer == n - 1) return 1;
    // 마지막 아니면 착수 후 레이어 깊게
    prev_x[layer] = x;
    int ret = 0;
    for (int i = 0; i < n; i++) ret += solve(i, layer + 1);

    return ret;
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    int result = 0;
    for (int x = 0; x < n; x++) result += solve(x, 0);
    cout << result << '\n';

    return 0;
}
