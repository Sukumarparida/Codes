class Solution {
public:

    bool helper(vector<int>&weights,int guess , int days){
        int sum=0;
        int n =weights.size();
        int k=1;
       for(int i=0;i<n;i++){
        if(sum + weights[i] > guess){
            k++;
            sum =weights[i];
        }else{
            sum+=weights[i];
        }
       }
       if( k <= days){
        return true;
       }
       return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low =0;
        int high=0;
        for(int i=0;i<weights.size();i++){
            low = max(weights[i] , low);
            high+=weights[i];
        }
        int res =-1;
        while(low <= high){
            int guess = (low + high) /2;
            if(helper(weights,guess,days)){
                res = guess;
                high = guess -1;
            }else{
                low = guess +1;
            }
        }
        return res;
    }
};