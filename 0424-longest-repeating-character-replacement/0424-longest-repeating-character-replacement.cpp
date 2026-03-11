class Solution {
public:

    int maxcount(vector<int>& arr){
        int maxc = 0;
        for(int i=0;i<arr.size();i++){
            maxc=max(maxc , arr[i]);
        }
        return maxc;
    }
    int characterReplacement(string s, int k) {
        int low =0 , high =0 ,res = 0;
        vector<int> arr(256,0);
        for(high=0;high<s.size();high++){
            arr[s[high]]++;
            int maxc=maxcount(arr);
            int len = high - low +1;
            int diff =len -maxc;

            while(diff > k){
                arr[s[low]]--;
                low++;
                 maxc=maxcount(arr);
                  len = high - low +1;
                  diff = len - maxc;
            }
            len = high - low +1;
            res = max(res,len);
        }
        return res;
    }
};