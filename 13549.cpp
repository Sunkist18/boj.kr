#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pii;

#define GCD(x, y) __gcd(x, y)
#define LCM(x, y) (x * y) / __gcd(x, y)

int n, k;
int here, cost;
vector<int> upper;

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;
    priority_queue<pii> pq;
    upper.resize(100001);
    for (int i = 0; i <= 100000; i++) upper[i] = 987654321;
    upper[n] = 0;
    pq.push({-0, n});

    while (!pq.empty()) {
        tie(cost, here) = pq.top(); pq.pop();
        cost = -cost;
        for (int i = 0; i < 3; i++) {
            int next = (i == 0 ? here - 1 : i == 1 ? here + 1 : here * 2);
            int dist = (i == 2 ? 0 : 1);
            if (next < 0 or next > 100001) continue;
            if (cost + dist < upper[next]) {
                upper[next] = cost + dist;
                pq.push({-upper[next], next});
            }
        }
    }
    cout << upper[k];
    // for (int i = 0; i <= 100000; i++) {
    //     cout << i << ' ' << upper[i] << '\n';
    // }
    
    return 0;
}