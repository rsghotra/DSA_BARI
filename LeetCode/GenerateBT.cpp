/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    static int preIndex;
    int SearchInOrder(const vector<int>& inorder, int start, int end, int data);
    TreeNode* _buildTree(const vector<int>& preorder, const vector<int>& inorder, int inorderStart, int inorderEnd);
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
};

int Solution::SearchInOrder(const vector<int>& inorder, int start, int end, int data) {
    int index;
    for(int i{start}; i < end; ++i) {
        if(inorder.at(i) == data) {
            index = i;
            break;
        }
    }
    return index;
}

int Solution::preIndex = 0;

TreeNode* Solution::_buildTree(const vector<int>& preorder, const vector<int>& inorder, int inorderStart, int inorderEnd) {
    //recursive break
    if(inorderStart > inorderEnd) {
        return nullptr;
    }
    
    //start building root
    TreeNode* root = new TreeNode();
    root->val = preorder.at(preIndex);
    preIndex++;
    
    //if the given node is leaf node
    if(inorderStart == inorderEnd) {
        return root;
    }
    
    int splitIndex = SearchInOrder(inorder, inorderStart, inorderEnd, root->val);
    
    root->left = _buildTree(preorder, inorder, inorderStart, splitIndex - 1);
    root->right= _buildTree(preorder, inorder, splitIndex+1, inorderEnd);
    return root;
}

TreeNode* Solution::buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode* root = _buildTree(preorder, inorder, 0, inorder.size() - 1);
    this->preIndex = 0;
    return root;
}