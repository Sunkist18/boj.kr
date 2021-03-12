#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pii;

#define GCD(x, y) __gcd(x, y)
#define LCM(x, y) (x * y) / __gcd(x, y)

int n, m;
int inDgree[32001];
vector<vector<int>> adj;

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    adj.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int first, second;
        cin >> first >> second;
        adj[first].push_back(second);
        inDgree[second]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) if (!inDgree[i]) q.push(i);

    while (!q.empty()) {
        int here = q.front(); q.pop();
        cout << here << ' ';
        for (auto there : adj[here]) {
            if(!--inDgree[there]) q.push(there);
        }
    }
    return 0;
}
