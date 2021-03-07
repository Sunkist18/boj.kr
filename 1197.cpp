#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pii;

#define GCD(x, y) __gcd(x, y)
#define LCM(x, y) (x * y) / __gcd(x, y)

vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge (int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (x < y) parent[y] = x;
        else parent[x] = y;
    }
}

int v, e;
int a, b;
priority_queue<pair<int, pii>> pq;

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> v >> e;

    parent.resize(v + 1);
    for (int i = 0; i < v + 1; i++) parent[i] = i;

    for (int i = 0; i < e; i++) {
        int here, there, cost;
        cin >> here >> there >> cost;
        pq.push({-cost, {here, there}});
    }

    int result = 0;

    while (!pq.empty()) {
        pair<int, pii> here = pq.top();
        tie(a, b) = here.second;
        if (find(a) != find(b)) {
            merge(a, b);
            result += -(here.first);
        }
        pq.pop();
    }
    cout << result;
    return 0;
}
