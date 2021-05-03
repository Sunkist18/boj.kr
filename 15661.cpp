//
// Created by 최민우 on 2021/05/02.
//


#include <bits/stdc++.h>

using namespace std;

int n;
int field[20][20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> field[i][j];
    int result = 987654321;
    for (int i = n - 1; i > 0; i--) {
        vector<int> choose;
        choose.resize(n);
        for (int j = i; j < n; j++) choose[j] = 1;
        do {
            int gap = 0;
            for (int here = 0; here < n; here++) {
                for (int there = here + 1; there < n; there++) {
                    if (choose[here] == choose[there]) {
                        gap += (choose[here] ? -1 : 1) * (field[here][there] + field[there][here]);
                    }
                }
            }
            result = min(abs(gap), result);
        } while (next_permutation(choose.begin(), choose.end()));
    }
    cout << result;
    return 0;
}