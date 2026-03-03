class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater=0;
        int i=0,j=height.size()-1;
        int width=0;
        int ht=0;
        int currwater=0;
        while(i<j){
            width = j-i;
            ht = min(height[i] , height[j]);
            currwater= width * ht;
            maxwater = max(maxwater,currwater);
            height[i] < height[j] ? i++ : j--;
        }
        return maxwater;
    }
};