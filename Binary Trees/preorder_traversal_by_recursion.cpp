void traversal(TreeNode* root, vector<int>& ans) {
    // Base condition
    if(root) {
        ans.push_back(root -> val);
        traversal(root -> left, ans);
        traversal(root -> right, ans);
    }
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    traversal(root, ans);

    return ans;
}