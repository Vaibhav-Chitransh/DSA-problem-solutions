/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_map<int, bool> childHasParent;

        for (auto description : descriptions) {
            int parentVal = description[0];
            int childVal = description[1];
            int isLeft = description[2];

            TreeNode* parentNode = nullptr;
            TreeNode* childNode = nullptr;

            if (nodeMap.find(parentVal) == nodeMap.end()) parentNode = new TreeNode(parentVal);
            else parentNode = nodeMap[parentVal];

            if (nodeMap.find(childVal) == nodeMap.end()) childNode = new TreeNode(childVal);
            else childNode = nodeMap[childVal];

            if (isLeft) parentNode->left = childNode;
            else parentNode->right = childNode;

            nodeMap[parentVal] = parentNode;
            nodeMap[childVal] = childNode;
            childHasParent[childVal] = true;
        }

        TreeNode* root = nullptr;
        for (auto [nodeVal, node] : nodeMap) {
            if (!childHasParent[nodeVal]) root = node;
        }

        return root;
    }
};
