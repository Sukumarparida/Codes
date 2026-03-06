class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        int size = nums.size();

        for(int i = 0; i < size; i++){
            if(nums[i] >= 0){
                pos.push_back(nums[i] * nums[i]);
            }else{
                neg.push_back(nums[i] * nums[i]);
            }
        }

        reverse(neg.begin(), neg.end());

        if(pos.size() == 0){ // all negative
            return neg;
        }

        if(neg.size() == 0){ // all positive
            return pos;
        }

        int i = 0;
        int j = 0;
        int idx = 0;
        int n = pos.size();
        int m = neg.size();

        vector<int> res(m + n);

        while(i < n && j < m){
            if(neg[j] < pos[i]){
                res[idx] = neg[j];
                idx++;
                j++;
            }else{
                res[idx] = pos[i];
                idx++;
                i++;
            }
        }

        while(j < m){
            res[idx] = neg[j];
            idx++;
            j++;
        }

        while(i < n){
            res[idx] = pos[i];
            idx++;
            i++;
        }

        return res;
    }
};