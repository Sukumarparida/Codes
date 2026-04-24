class Solution {
public:
    long long helper(vector<int>& piles, int n, int speed){
        long long h = 0;

        for(int i = 0; i < n; i++){
            h = h+ piles[i]  / speed;             

            if(piles[i] % speed != 0){          
                h++;
            }
        }
        return h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = piles[0];
        int result = -1;
        int n = piles.size();

        for(int i = 1; i < n; i++){
            if(piles[i] > high){
                high = piles[i];
            }
        }

        while(low <= high){
            long long guess = low + (high -  low) / 2;

            long long hour = helper(piles, n, guess);

            if(hour > h){
                low = guess + 1;
            } else {
                result = guess;
                high = guess - 1;
            }
        }

        return result;
    }
};