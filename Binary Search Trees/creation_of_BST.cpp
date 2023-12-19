#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        // Constructor
        Node(int d) {
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }
};

Node* insertIntoBST(Node* root, int data) {
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data > root -> data) {
        root -> right = insertIntoBST(root -> right, data);
    }

    else {
        root -> left = insertIntoBST(root -> left, data);
    }
}

void takeInput(Node* root) {
    int data;
    cin >> data;

    while(data != -1) {
        insertIntoBST(root, data);
        cin >> data;
    }
}

void traversal(Node* root, vector<int>& ans) {
    // Base condition
    if(root) {
        ans.push_back(root -> data);
        traversal(root -> left, ans);
        traversal(root -> right, ans);
    }
}

vector<int> preOrderTraversal(Node* root) {
    vector<int> ans;
    traversal(root, ans);

    return ans;
}

int main(){
    Node* root = NULL;

    cout << "Enter the data" << endl;
    takeInput(root);

    cout << "Printing the pre order traversal of BST" << endl;
    vector<int> res = preOrderTraversal(root);

    for(int i=0; i<res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}