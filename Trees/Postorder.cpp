/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode *last = NULL;
    while(root || !st.empty()) {
        if (root) {
            st.push(root);
            root = root->left;
        } else {
            TreeNode* temp = st.top();
            if (temp->right && last != temp->right) {
                root = temp->right;
            } else {
                res.push_back(temp->val);
                last = temp;
                st.pop();
            }
        }
    }
    return res;
}
