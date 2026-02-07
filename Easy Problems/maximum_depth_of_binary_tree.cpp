#include <iostream>
#include <algorithm>
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

// Function to find maximum depth
int maxDepth(TreeNode* root) {

    // if tree is empty
    if (root == NULL) {
        return 0;
    }

    // find depth of left subtree
    int leftDepth = maxDepth(root->left);

    // find depth of right subtree
    int rightDepth = maxDepth(root->right);

    // return max depth
    return 1 + max(leftDepth, rightDepth);
}

int main() {
    /*
        Example tree:
            3
           / \
          9  20
             / \
            15  7
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int depth = maxDepth(root);
    cout << "Maximum Depth of Tree: " << depth << endl;

    return 0;
}