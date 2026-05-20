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
    bool res =false;
    void helper(TreeNode* root , int sum ,int target){
        if(root == nullptr)
            return;
        sum = sum + root->val;
        if(root->left == nullptr && root->right == nullptr){
            if(sum == target){
                res = true;
                return;
            }
        }
        helper(root->left,sum,target);
         helper(root->right,sum,target);
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        helper(root,sum,targetSum);
        return res;
    }
};