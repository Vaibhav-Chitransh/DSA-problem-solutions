void traversal(TreeNode* root, vector<int>& ans) {
        if(root) {
            traversal(root -> left, ans);
            traversal(root -> right, ans);

            ans.push_back(root -> val);
        }
}

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        traversal(root, ans);

        return ans;
}