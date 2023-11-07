class Node {
    public:
        int data;
        Node* left;
        Node* right:

        Node(int value) {
            this -> data = value;
            this -> left = NULL;
            this -> right = NULL;
        }
};

Node* buildTree(Node* root) {
    int data;
    cout << "Enter the data: ";
    cin >> data;

    root = new Node(data);

    // Base condition
    if(data == -1) {
        return NULL;
    }

    cout << "Enter the data for inseting in left of " << data << endl;
    root -> left = buildTree(root -> left);

    cout << "Enter the data for inseting in right of " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}