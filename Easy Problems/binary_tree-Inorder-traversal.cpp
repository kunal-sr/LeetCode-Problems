#include <iostream>
#include <vector>
#include <stack>
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

// Inorder traversal function (iterative)
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* current = root;

    while (current != NULL || !st.empty()) {

        // go to the leftmost node
        while (current != NULL) {
            st.push(current);
            current = current->left;
        }

        // process current node
        current = st.top();
        st.pop();
        result.push_back(current->val);

        // move to right subtree
        current = current->right;
    }

    return result;
}

int main() {
    /*
        Example tree:
            1
             \
              2
             /
            3
    */

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}