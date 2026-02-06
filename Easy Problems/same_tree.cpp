#include <iostream>
using namespace std;

// Definition of tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// Function to check if two trees are the same
bool isSameTree(TreeNode* p, TreeNode* q) {

    // if both are NULL
    if (p == NULL && q == NULL) {
        return true;
    }

    // if one is NULL and the other is not
    if (p == NULL || q == NULL) {
        return false;
    }

    // if values are different
    if (p->val != q->val) {
        return false;
    }

    // check left and right subtrees
    return isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}

int main() {
    /*
        Tree p:
            1
           / \
          2   3

        Tree q:
            1
           / \
          2   3
    */

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    if (isSameTree(p, q)) {
        cout << "Trees are the same" << endl;
    } else {
        cout << "Trees are NOT the same" << endl;
    }

    return 0;
}