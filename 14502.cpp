#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pii;

#define GCD(x, y) __gcd(x, y)
#define LCM(x, y) (x * y) / __gcd(x, y)

int max_x, max_y;
int x, y, dx, dy;
vector<vector<int>> field;
vector<pii> blank;
vector<pii> virus;
vector<pii> tmp_virus;
vector<pii> tmp_blank;
vector<pii> delta;

void spread_virus() {
    queue<pii> q;
    for (auto e : virus) q.push(e);
    while (!q.empty()) {
        tie(x, y) = q.front(); q.pop();
        for (auto d : delta) {
            tie(dx, dy) = d;
            if (x + dx < 0 or x + dx >= max_x or y + dy < 0 or y + dy >= max_y) continue;
            if (field[y + dy][x + dx] != 0) continue;
            tmp_virus.emplace_back(x + dx, y + dy);
            field[y + dy][x + dx] = 3;
            q.push({x + dx, y + dy});
        }
    }
}

// int search_bfs(int ix, int iy) {
//     int ret = 1;
//     queue<pii> q;
//     tmp_blank.emplace_back(ix, iy);
//     field[iy][ix] = 1;
//     q.push({ix, iy});
//     while (!q.empty()) {
//         tie(x, y) = q.front(); q.pop();
//         for (auto d : delta) {
//             tie(dx, dy) = d;
//             if (x + dx < 0 or x + dx >= max_x or y + dy < 0 or y + dy >= max_y) continue;
//             if (field[y + dy][x + dx] != 0) continue;
//             tmp_blank.emplace_back(x + dx, y + dy);
//             field[y + dy][x + dx] = 1;
//             ret += 1;
//             q.push({x + dx, y + dy});
//         }
//     }
//     return ret;
// }

int search_zero() {
    int ret = 0;
    // blank vector 최적화 가능
    for (int y = 0; y < max_y; y++) {
        for (int x = 0; x < max_x; x++) {
            ret += field[y][x] == 0;
        }
    }
    return ret;
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    delta.push_back({0, 1});
    delta.push_back({1, 0});
    delta.push_back({0, -1});
    delta.push_back({-1, 0});

    cin >> max_y >> max_x;

    field.resize(max_y);
    for (int y = 0; y < max_y; y++) {
        field[y].resize(max_x);
        for (int x = 0; x < max_x; x++) {
            cin >> field[y][x];
            if (field[y][x] == 0) {
                blank.emplace_back(x, y);
            } else if (field[y][x] == 2) {
                virus.emplace_back(x, y);
            }
        }
    }
    int result = 0;
    vector<int> choose;
    choose.resize(blank.size());
    for (int i = 0; i < 3; i++) choose[i] = 1;
    do {
        for (int i = 0; i < blank.size(); i++) {
            if (choose[i]) {
                tie(x, y) = blank[i];
                field[y][x] = 1;
            }
        }
        tmp_virus.clear();
        spread_virus();
        
        tmp_blank.clear();
        result = max(result, search_zero());
        // int cmw = search_zero();
        // if (cmw > result) {
        //     result = cmw;
        // }

        // if (result == 26) {
        //     for (auto k : field) {
        //         for (auto e : k) cout << e << ' ';
        //         cout << '\n';
        //     }
        // }

        for (auto e : tmp_blank) {
            tie(x, y) = e;
            field[y][x] = 0;
        } for (auto e : tmp_virus) {
            tie(x, y) = e;
            field[y][x] = 0;
        } 
        for (int i = 0; i < blank.size(); i++) {
            if (choose[i]) {
                tie(x, y) = blank[i];
                field[y][x] = 0;
            }
        }
    } while (prev_permutation(choose.begin(), choose.end()));
    
    cout << result << '\n';
    return 0;
}