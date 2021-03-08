#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pii;

#define GCD(x, y) __gcd(x, y)
#define LCM(x, y) (x * y) / __gcd(x, y)

string line, explosive;

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    stack<pair<char, int>> field;
    
    cin >> line >> explosive;
    for (auto c : line) {
        if (field.size() and explosive[field.top().second + 1] == c) {
            field.push({c, field.top().second + 1});
        } else if (c == explosive[0]) {
            field.push({c, 0});
        } else {
            field.push({c, -1});
        } if (field.top().second == explosive.size() - 1) {
            for (int i = 0; i < explosive.size(); i++) field.pop();
        }
    }

    if (field.empty()) {
        cout << "FRULA" << '\n';
        return 0;
    }

    string result;
    while (!field.empty()) {
        result.push_back(field.top().first);
        field.pop();
    } reverse(result.begin(), result.end());
    cout << result;
    
    return 0;
}
