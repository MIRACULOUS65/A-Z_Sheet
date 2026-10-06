/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/
class BSTIterator {
    stack<TreeNode*> st;
    bool reverse;

    // Helper function to push all left or right nodes
    void pushAll(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = (reverse) ? node->right : node->left;
        }
    }

   public:
    BSTIterator(TreeNode* root, bool isReverse) : reverse(isReverse) {
        pushAll(root);
    }

    // Check if there are more elements in the BST
    bool hasNext() { return !st.empty(); }

    // Get the next element in the inorder or reverse inorder traversal
    int next() {
        TreeNode* node = st.top();
        st.pop();
        if (!reverse)
            pushAll(node->right);
        else
            pushAll(node->left);
        return node->data;
    }
};

class Solution {
   public:
    bool twoSumBST(TreeNode* root, int k) {
       if (!root) return false;
        
        // Initialize two iterators
        BSTIterator l(root, false); // normal inorder
        BSTIterator r(root, true);  // reverse inorder
        
        int i = l.next();
        int j = r.next();
        
        while (i < j) {
            if (i + j == k) return true;
            else if (i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};