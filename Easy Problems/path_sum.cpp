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

// Function to check path sum
bool hasPathSum(TreeNode* root, int targetSum) {

    // if tree is empty
    if (root == NULL) {
        return false;
    }

    // subtract current node value
    targetSum = targetSum - root->val;

    // if leaf node
    if (root->left == NULL && root->right == NULL) {
        return targetSum == 0;
    }

    // check left or right subtree
    return hasPathSum(root->left, targetSum) ||
           hasPathSum(root->right, targetSum);
}

int main() {
    /*
        Example tree:
                5
               / \
              4   8
             /   / \
            11  13  4
           /  \       \
          7    2       1
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    if (hasPathSum(root, targetSum)) {
        cout << "Path with sum " << targetSum << " exists" << endl;
    } else {
        cout << "Path with sum " << targetSum << " does NOT exist" << endl;
    }

    return 0;
}