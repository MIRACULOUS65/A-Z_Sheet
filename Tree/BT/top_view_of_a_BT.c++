#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    // Constructor to initialize the node with a value
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to return the top view of the binary tree
    vector<int> topView(TreeNode *root) {
        // Vector to store the result
        vector<int> ans;
        
        // Check if the tree is empty
        if (root == nullptr) {
            return ans;
        }
        
        // Map to store the top view nodes based on their vertical positions
        map<int, int> mpp;
        
        // Queue for BFS traversal, each element is a pair containing node and its vertical position
        queue<pair<TreeNode*, int>> q;
        
        // Push the root node with its vertical position (0) into the queue
        q.push({root, 0});
        
        // BFS traversal
        while (!q.empty()) {
            // Retrieve the node and its vertical position from the front of the queue
            auto it = q.front();
            q.pop();
            TreeNode *node = it.first;
            int line = it.second;
            
            // If the vertical position is not already in the map, add the node's data to the map
            if (mpp.find(line) == mpp.end()) {
                mpp[line] = node->data;
            }
            
            // Process left child
            if (node->left != nullptr) {
                // Push the left child with a decreased vertical position into the queue
                q.push({node->left, line - 1});
            }
            
            // Process right child
            if (node->right != nullptr) {
                // Push the right child with an increased vertical position into the queue
                q.push({node->right, line + 1});
            }
        }
        
        // Transfer values from the map to the result vector
        for (auto it : mpp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};

int main() {
    // Creating a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(10);
    root->right->left = new TreeNode(9);

    Solution solution;

    // Get the top view traversal
    vector<int> topView = solution.topView(root);

    // Print the result
    cout << "Top View Traversal: " << endl;
    for (auto node : topView) {
        cout << node << " ";
    }

    return 0;
}
