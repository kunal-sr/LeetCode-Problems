#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode* root, vector<int>& nodes) {
    if (!root) return;
    inorder(root->left, nodes);
    nodes.push_back(root->val);
    inorder(root->right, nodes);
}

TreeNode* buildBST(vector<int>& nodes, int left, int right) {
    if (left > right) return NULL;

    int mid = (left + right) / 2;
    TreeNode* root = new TreeNode(nodes[mid]);

    root->left = buildBST(nodes, left, mid - 1);
    root->right = buildBST(nodes, mid + 1, right);

    return root;
}

TreeNode* balanceBST(TreeNode* root) {
    vector<int> nodes;
    inorder(root, nodes);

    return buildBST(nodes, 0, nodes.size() - 1);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    TreeNode* balanced = balanceBST(root);

    cout << "BST balanced successfully\n";
    return 0;
}
