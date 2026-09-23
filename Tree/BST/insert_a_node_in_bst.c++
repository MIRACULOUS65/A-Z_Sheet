/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
   public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // your code goes here
        if (root == NULL) {
            return new TreeNode(val);
        }
        TreeNode *cur=root;
        while (true) {
            if (cur->val<=val) {
                if(cur->right!=NULL) cur=cur->right;
                else{
                    cur->right= new TreeNode(val);
                    break;
                }
            }
            else (cur->val>=val) {
                if(cur->left!=NULL) cur=cur->left;
                else{
                    cur->left= new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};