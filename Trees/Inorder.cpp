/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    
    stack<TreeNode*> st;
    while(1) {
        while(root) {
            st.push(root);
            root = root->left;
        }
        if (st.empty()) break;
        root = st.top();
        st.pop();
        res.push_back(root->val);
        root = root->right;
    }
    return res;
}
