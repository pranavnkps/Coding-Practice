//SOLUTION 1 - O(N)
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
    int count = 0;
    int countNodes(TreeNode* root) {
        preorder(root);
        return count;
    }
    void preorder(TreeNode* root){
        if(root == NULL)
            return;
        count++;
        preorder(root->left);
        preorder(root->right);
    }
};

// SOLUTION 2 - O(log^2(N))

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        int h = height(root);
        if(height(root->right) == h-1)
            return pow(2,h) + countNodes(root->right);
        else
            return pow(2,h-1) + countNodes(root->left);
    }
    
    int height(TreeNode* root){
        if(root == NULL)
            return -1;
        return 1 + height(root->left);
    }
};