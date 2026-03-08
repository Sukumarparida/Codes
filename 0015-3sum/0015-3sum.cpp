class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        set<vector<int>>s;
        int sum=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            int k =nums.size()-1;
            while(j<k){
                sum = (nums[i] + nums[j] + nums[k]);
                if(sum == 0){
                    s.insert({nums[i] , nums[j] , nums[k]});
                    j++;
                    k--;
                }else if(sum < 0){
                    j++;
                }else{
                    k--;
                }
            }
        }
        for(auto ans : s){
            output.push_back(ans);
        }
        return output;
    }
};