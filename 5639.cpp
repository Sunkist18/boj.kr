#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pii;

#define GCD(x, y) __gcd(x, y)
#define LCM(x, y) (x * y) / __gcd(x, y)

struct Node {
    int data;
    Node * left;
    Node * right;
};

Node* insert(Node* node, int data) {
    if (node == nullptr) {
        node = new Node();
        node->data = data;
        node->left = node->right = nullptr;
    } else if (data <= node->data) node->left = insert(node->left, data);
    else node->right = insert(node->right, data);
    return node;
}

void post_order(Node* node) {
    if (node->left != nullptr) post_order(node->left);
    if (node->right != nullptr) post_order(node->right);
    cout << node->data << '\n';
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Node * root = nullptr;

    int data;
    while (cin >> data) root = insert(root, data);
    
    if (root != nullptr) post_order(root);

    return 0;
}
