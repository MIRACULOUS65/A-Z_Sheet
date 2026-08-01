/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathDown(root,maxi);
        return maxi;
    }

    int maxPathDown(TreeNode* node, int &maxi){
        if(node==NULL){
            return 0;
        }
        int left = max(0,maxPathDown(node->left,maxi));
        int right = max(0,maxPathDown(node->right,maxi));
        maxi = max(maxi,left+right+node->val);
        return max(left,right) + node->val;
    }
};

// or more simply from out beloved codestorywithMIK

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum;

    int solve(TreeNode* root) {
        if (root == NULL)
            return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        int neeche_hi_mil_gaya_answer = l + r + root->val;   //(1)

        int koi_ek_acha = max(l, r) + root->val;             //(2)

        int only_root_acha = root->val;                      //(3)

        maxSum = max({maxSum,
                      neeche_hi_mil_gaya_answer,
                      koi_ek_acha,
                      only_root_acha});

        // most important part
        return max(koi_ek_acha, only_root_acha);
    }

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;

        solve(root);

        return maxSum;
    }
};