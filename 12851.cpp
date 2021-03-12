#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pii;

#define GCD(x, y) __gcd(x, y)
#define LCM(x, y) (x * y) / __gcd(x, y)

int n, k;
int visited[100001];

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;
    int time = -1, cnt = 0;
    queue<pii> q;
    q.push({n, 0});
    while (!q.empty()) {
        int here, cost;
        tie(here, cost) = q.front(); q.pop();
        visited[here] = true;
        if (time != -1 and cost > time) break;
        if (here == k) {
            time = cost;
            cnt += 1;
        }
        for (int i = 0; i < 3; i++) {
            int next = (i == 0 ? here + 1 : i == 1 ? here - 1 : here * 2);
            if (0 <= next and next <= 100000 and !visited[next]) {
                q.push({next, cost + 1});
            }
        }
    }
    cout << time << '\n' << cnt;
    return 0;
}
