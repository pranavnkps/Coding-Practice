/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> array;
        TreeNode* root = NULL;
        while(head != NULL){
            array.push_back(head->val);
            head = head->next;
        }
        if(array.empty())
            return root;
       buildTree(root,array,0,array.size()-1);
        return root;
    }
    
    void buildTree(TreeNode*& root, vector<int> array, int l, int r){
        TreeNode* temp = new TreeNode();
        int mid = (l+r)/2;
        if(l == r){
            temp->val = array[l];
            temp->left = temp->right = NULL;
            root = temp;
            return;
        }
        temp->val = array[mid];
        temp->left = NULL;
        temp->right = NULL;
        root = temp;
        if(r >= mid+1)
        buildTree(root->right, array, mid+1, r);
        if(l <= mid-1)
        buildTree(root->left, array, l , mid-1);
        
    }
};