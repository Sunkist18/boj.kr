#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pii;

int n, m, r;
vector<int> points;
vector<vector<pii>> field;
int from, to, cost;
int here, there, path;

int solve(vector<int> dist) {
    int ret = 0;
    for (int i = 0; i < n; i++) ret += (dist[i] <= m ? points[i] : 0);
    return ret;
}

vector<int> dijkstra(int v) {
    vector<int> dist;
    dist.resize(n);
    for (int i = 0; i < n; i++) dist[i] = 987654321;
    dist[v] = 0;
    priority_queue<pii> pq;
    pq.push({-0, v});

    while (!pq.empty()) {
        tie(cost, here) = pq.top(); pq.pop();
        cost = -cost;
        for (auto next_node : field[here]) {
            tie(there, path) = next_node;
            if (cost + path < dist[there]) {
                dist[there] = cost + path;
                pq.push({-dist[there], there});
            }
        }
    }
    return dist;
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> r;
    points.resize(n);
    field.resize(n);
    for (auto &e : points) cin >> e;

    for (int i = 0; i < r; i++) {
        cin >> from >> to >> cost;
        field[from - 1].emplace_back(to - 1, cost);
        field[to - 1].emplace_back(from - 1, cost);
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        result = max(result, solve(dijkstra(i)));
    }

    cout << result << '\n';

    return 0;
}