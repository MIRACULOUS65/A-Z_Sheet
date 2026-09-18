#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    // Constructor to initialize the node with a value
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to return the Right view of the binary tree
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        // Get the level order traversal of the tree
        vector<vector<int>> levelTraversal = levelOrder(root);

        // Iterate through each level and add the last element to the result
        for (auto level : levelTraversal) {
            res.push_back(level.back());
        }

        return res;
    }

    // Function to return the Left view of the binary tree
    vector<int> leftSideView(TreeNode* root) {
        vector<int> res;

        // Get the level order traversal of the tree
        vector<vector<int>> levelTraversal = levelOrder(root);

        // Iterate through each level and add the first element to the result
        for (auto level : levelTraversal) {
            res.push_back(level.front());
        }

        return res;
    }

private:
    // Function that returns the level order traversal of a Binary tree 
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        // Return an empty vector if the tree is empty
        if (!root) {
            return ans;
        }

        // Use a queue to perform level order traversal
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            // Process each node in the current level
            for (int i = 0; i < size; i++) {
                TreeNode* top = q.front();
                level.push_back(top->data);
                q.pop();

                // Enqueue the left child if it exists
                if (top->left != NULL) {
                    q.push(top->left);
                }

                // Enqueue the right child if it exists
                if (top->right != NULL) {
                    q.push(top->right);
                }
            }

            // Add the current level to the result
            ans.push_back(level);
        }

        return ans;
    }
};

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(10);
    root->right->left = new TreeNode(9);

    Solution solution;

    // Get the Right View traversal
    vector<int> rightView = solution.rightSideView(root);

    // Print the result for Right View
    cout << "Right View Traversal: ";
    for (auto node : rightView) {
        cout << node << " ";
    }
    cout << endl;

    // Get the Left View traversal
    vector<int> leftView = solution.leftSideView(root);

    // Print the result for Left View
    cout << "Left View Traversal: ";
    for (auto node : leftView) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
