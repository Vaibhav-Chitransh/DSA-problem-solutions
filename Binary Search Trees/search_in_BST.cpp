bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if(root == NULL) {
        return false;
    }

    if(x == root -> data) {
        return true;
    }

    if(x > root -> data) {
        searchInBST(root -> right, x);
    }

    else if(x < root -> data) {
        searchInBST(root -> left, x);
    }
}