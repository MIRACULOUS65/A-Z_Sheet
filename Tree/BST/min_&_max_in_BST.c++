/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode* left;
 *     TreeNode* right;
 * };
 */

class Solution {
public:
    vector<int> findMinMax(TreeNode* root) {
        // Your code goes here
        TreeNode* minimumNode = root;
        TreeNode* maximumNode = root;

        while(minimumNode->left != NULL){
            minimumNode = minimumNode->left;
        }

        while(maximumNode->right != NULL){
            maximumNode = maximumNode->right;
        }

        return {minimumNode->val, maximumNode->val};
    }
};