/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    void helper(TreeNode* root,TreeNode* p , TreeNode* q){
            if(root == nullptr)
                return;
            if(root == p && root == q){
                    ans = root;
                return;
            }
            if(root->val < p->val){
                helper(root->right , p ,q);
            }else if(root->val > q->val){
                helper(root->left ,p ,q);
            }else{
                ans =root;
                return;
            }
                
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < q->val){
            helper(root,p,q);
        }else
        helper(root , q , p);
    return ans;
    }
};