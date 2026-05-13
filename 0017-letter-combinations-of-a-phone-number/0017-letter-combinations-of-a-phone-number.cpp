class Solution {
public:
void helper(string &digits,int idx,int n,string &diary,vector<string>& res){
    unordered_map<char,string>f;
    f['2'] ="abc";
    f['3'] ="def";
    f['4'] ="ghi";
    f['5'] ="jkl";
    f['6'] ="mno";
    f['7'] ="pqrs";
    f['8'] ="tuv";
    f['9'] ="wxyz";
    if(idx == n){
        res.push_back(diary);
        return;
    }
    string choice=f[digits[idx]];
    for(int j=0;j<choice.size();j++){
        diary.push_back(choice[j]);
        helper(digits,idx+1,n,diary,res);
        diary.pop_back();
    }
    return;
}
    vector<string> letterCombinations(string digits) {
        int n =digits.size();
        vector<string> res;
        string diary="";
        int idx =0;
        helper(digits,idx,n,diary,res);
        return res;
    }
};