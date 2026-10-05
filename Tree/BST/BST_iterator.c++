/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class BSTIterator{
    private: stack <TreeNode* > myStack;
	public:
		BSTIterator(TreeNode* root){
			pushAll(root);
		}
		
		bool hasNext(){
			return !myStack.empty();
		}
		
		int next(){
            TreeNode *tmpNode= myStack.top();
            myStack.pop();
            pushAll(tmpNode->right);
            return tmpNode->data;

		}

    private: 
        void pushAll(TreeNode *node){
            for(;node!=NULL;myStack.push(node),node=node->left);
        }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */