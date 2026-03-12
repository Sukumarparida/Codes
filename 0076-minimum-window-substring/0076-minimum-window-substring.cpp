class Solution {
public:

    bool fun(vector<int> &have, vector<int> &need)
{
    for(int i=0;i<256;i++)
    {
        if(have[i]<need[i])
        return false;
    }
    return true;
}

    string minWindow(string s, string t) {
        int S=s.size();
        int T =t.size();
        if(S<T) return "";
        vector<int> have(256 ,0);
        vector<int> need(256 ,0);
        for(int i=0;i<T;i++){
            need[t[i]]++;
        }
        int start = -1;
        int res = INT_MAX;
        int high =0 , low =0;
        for(high=0;high<S;high++){
            have[s[high]]++;
            while(fun(have,need)){
                int len = high - low +1;
                if(res > len){
                    res = len;
                    start =low;
                }
                have[s[low]]--;
                low++;
            }
        }
        if(res == INT_MAX) 
        return "";
        return s.substr(start , res);
    }
};