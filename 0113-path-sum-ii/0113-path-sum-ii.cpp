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
vector<vector<int>>res;
void helper(TreeNode* root,int sum ,int targetSum , vector<int> diary){
    if(root == nullptr)
        return;
    sum = sum + root->val;
    diary.push_back(root->val);
    if(root->left == nullptr && root->right == nullptr){
            if(sum == targetSum){
                res.push_back(diary);
                diary.pop_back();
                return;
            }
    }
            helper(root->left,sum,targetSum,diary);
            helper(root->right,sum,targetSum,diary);
            diary.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> diary;
        helper(root,0,targetSum,diary);
        return res;
    }
};