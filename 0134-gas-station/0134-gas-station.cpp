class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank =0,curr=0,st=0;
        for(int i=0;i<gas.size();i++){
            int gain =gas[i] - cost[i];
            total_tank +=gain , curr+=gain;
            if(curr <0){
                curr=0;
                st=i+1;
            }

        }
        if(total_tank>=0){
            return st;
        }
        return -1;
    }
};