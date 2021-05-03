//
// Created by 최민우 on 2021/05/04.
//


#include <bits/stdc++.h>
#define int long long

using namespace std;
int n;

vector<vector<int>> adj;
vector<int> priority;
vector<int> given;
vector<bool> visited;

int bfs() {
    queue<int> q;
    q.push(0);
    visited[0] = true;

    int idx = 0;
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        if (here != given[idx++]) return 0;
        for (int there : adj[here]) {
            if (visited[there]) continue;
            visited[there] = true;
            q.push(there);
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
    adj.resize(n);
    given.resize(n);
    priority.resize(n);
    visited.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int here, there;
        cin >> here >> there;
        adj[--here].push_back(--there);
        adj[there].push_back(here);
    }

    for (int i = 0; i < n; i++) {
        cin >> given[i];
        priority[--given[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end(), [&](const int &u, const int &v) {
            return priority[u] < priority[v];
        });
    }

    cout << bfs();
    return 0;
}