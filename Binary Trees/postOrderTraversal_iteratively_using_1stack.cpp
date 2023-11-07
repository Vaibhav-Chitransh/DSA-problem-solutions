vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    TreeNode* curr = root;

    if(root == NULL) {
        return ans;
    }

    stack<TreeNode*> st;

    while(curr != NULL || !st.empty()) {
        if(curr != NULL) {
            st.push(curr);
            curr = curr -> left;
        }

        else {
            TreeNode* temp = st.top() -> right;
            if(temp == NULL) {
                temp = st.top();
                st.pop();
                ans.push_back(temp -> val);

                while(!st.empty() && temp == st.top() -> right) {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp -> val);
                }
            }
            else {
                curr = temp;
            }
        }
    }
    return ans;
}