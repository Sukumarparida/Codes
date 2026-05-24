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
    TreeNode* prev=nullptr;
    TreeNode* w1first=nullptr;
    TreeNode* w1sec =nullptr;
    TreeNode* w2first=nullptr;
    TreeNode* w2sec=nullptr;
    int wrong=0;
    void helper(TreeNode* root){
        if(root == nullptr)
            return;
        helper(root->left);
        if(prev == nullptr){
            prev =root;
        }else{
            if(root->val < prev->val){
                if(wrong == 0){
                    w1first =prev;
                    w1sec =root;
                    wrong++;
                }else{
                    w2first=prev;
                    w2sec =root;
                    wrong++;
                }
                
            }  
            prev =root; 
        }
        helper(root->right);
    }
    void recoverTree(TreeNode* root) {
        helper(root);
        if(wrong ==1){
        swap(w1first->val,w1sec->val);
    }else{
        swap(w1first->val , w2sec->val);
    }
    }
};