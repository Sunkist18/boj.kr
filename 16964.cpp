//
// Created by 최민우 on 2021/05/04.
//


#include <bits/stdc++.h>
#define int long long
#define MAX 100001

using namespace std;

int n, here, there, idx;
vector<int> adj[MAX];
int priority[MAX], given[MAX];
bool visited[MAX];

int bfs() {
    visited[0] = true;
    stack<int> stk;
    stk.push(0);
    while (!stk.empty()) {
        here = stk.top(); stk.pop();
        if (here != given[idx++]) return 0;
        for (int u : adj[here]) {
            if (visited[u]) continue;
            visited[u] = true;
            stk.push(u);
        }
    }
    return idx == n;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> here >> there;
        here--, there--;
        adj[here].push_back(there);
        adj[there].push_back(here);
    }

    for (int i = 0; i < n; i++) {
        cin >> given[i];
        priority[--given[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end(), [&](const int &u, const int &v) {
            return priority[u] > priority[v];
        });
    }

    cout << bfs();

    return 0;
}