/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>postorder;
        stack<TreeNode*> st;
        TreeNode* curl = root;
        while(curl!=NULL || !st.empty()){
            if(curl!=NULL){
                st.push(curl);
                curl=curl->left;
            }
            else{
                auto temp = st.top()->right;
                if(temp==NULL){
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->val);
                    while(!st.empty() && temp==st.top()->right){
                        temp=st.top(),st.pop();
                        postorder.push_back(temp->val);
                    }
                }
                else{
                    curl=temp;
                }
            }
        }
        return postorder;
    }
};