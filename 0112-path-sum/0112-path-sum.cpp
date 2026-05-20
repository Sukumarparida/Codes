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
    bool res = false;
    void fun(TreeNode* root , int targetsum,int sum){
        if(root == nullptr)
            return;
        sum = sum + root->val;
        if(root->left == nullptr && root->right == nullptr)
            {
                if(sum == targetsum){
                         res =true;
                return;
                }
               
            }
            fun(root->left ,targetsum,sum);
            fun(root->right,targetsum,sum);
            return;


    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        fun(root,targetSum,sum);
        return res;   
    }
};