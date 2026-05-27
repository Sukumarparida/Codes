class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> prevrow;
        for(int i=0;i<numRows;i++){
            vector<int> currR(i+1,1);

        for(int j=1;j<i;j++){
            currR[j] =prevrow[j-1] + prevrow[j];
        }
        res.push_back(currR);
        prevrow =currR;
        }
        return res;
    }
};