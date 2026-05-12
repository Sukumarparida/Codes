class Solution {
public:
void helper(int open , int close, int n , string &temp ,vector<string>&res){
    if(open == n && close == n) {
            res.push_back(temp);
            return;
        }
    if(open <n){
        temp.push_back('(');
        helper(open+1,close,n,temp,res);
        temp.pop_back();
    }
    if(close<open){
        temp.push_back(')');
        helper(open,close+1,n,temp,res);
        temp.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string>res;
         string temp="";
        int open =0, close =0;
        helper(open,close,n,temp,res);
        return res;
    }
};