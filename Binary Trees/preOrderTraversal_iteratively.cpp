vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;

    if(root == NULL) {
        return ans;
    }
    
    stack<TreeNode*> s;
    s.push(root);

    while(!s.empty()) {
        root = s.top();
        s.pop();

        if(root -> right != NULL) {
            s.push(root -> right);
        }

        if(root -> left != NULL) {
            s.push(root -> left);
        }
        ans.push_back(root -> val);
    }
    return ans;
}