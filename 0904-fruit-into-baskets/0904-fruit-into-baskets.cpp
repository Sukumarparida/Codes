class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low =0;
        int high =0;
        int res = INT_MIN;
        unordered_map<int,int> h;
        for(high =0; high <fruits.size(); high++){
                h[fruits[high]]++;
                while(h.size() > 2){
                    h[fruits[low]]--;
                    if(h[fruits[low]] == 0)
                    h.erase(fruits[low]);
                    low++;
                }
                int len = high - low + 1;
                res = max(res , len);
        }
        if(res == INT_MIN) return -1;
        return res;
    }
};