void traversal(TreeNode* root, vector<int>& ans) {
    if(root) {
        traversal(root -> left, ans);
        ans.push_back(root -> val);
        traversal(root -> right, ans);
    }
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    traversal(root, ans);

    return ans;
}