class Solution {
public:
void helper(vector<int>&diary,vector<int>&candidates,int idx,int sum , int n ,
                            vector<vector<int>>& res ,int target){
                if(idx == n){
                    if(sum==target)
                    res.push_back(diary);
                    return;
                }
                helper(diary,candidates,idx+1,sum,n,res,target);
                if(candidates[idx] + sum<=target){
                    diary.push_back(candidates[idx]);
                    sum = sum + candidates[idx];
                    helper(diary,candidates,idx,sum,n,res,target);
                    diary.pop_back();
                    sum = sum - candidates[idx];
                }
                return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> diary;
        int n=candidates.size();
        vector<vector<int>> res;
        int idx =0;
        int  sum =0;
        helper(diary,candidates, idx,sum,n,res,target);
        return res;
    }
};