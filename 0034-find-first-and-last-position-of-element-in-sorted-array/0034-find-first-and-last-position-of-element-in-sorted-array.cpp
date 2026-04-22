class Solution {
public:

    int findfirst(vector<int>& nums , int x){
        int n =nums.size();
        int low =0;
        int high = n-1;
        int res =-1;
        while(low <= high){
            int guess = (low + high )/2;
            if(nums[guess] < x){
                low = guess +1;
            }else if(nums[guess] > x){
                high = guess -1;
            }else{
                res = guess;
                high = guess -1;
            }
        }
        return res;
    }
    int findlast(vector<int>& nums , int x){
        int n =nums.size();
        int low =0;
        int high = n-1;
        int res =-1;
        while(low <= high){
            int guess = (low + high )/2;
            if(nums[guess] < x){
                low = guess +1;
            }else if(nums[guess] > x){
                high = guess -1;
            }else{
                res = guess;
                low  = guess +1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findfirst(nums,target),findlast(nums,target)};
    }
};