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
    TreeNode* ans;
    TreeNode* helper(TreeNode* root, int val){
        if(root == nullptr)
            return nullptr;
        if(root->val == val){
             ans =root;
        return ans;
        }
           
        if(root->val > val){
             helper(root->left ,val);
        }else{
            helper(root->right,val);
        }
        return ans;
    }
        
    TreeNode* searchBST(TreeNode* root, int val) {
        helper(root,val);
        return ans;
    }
};