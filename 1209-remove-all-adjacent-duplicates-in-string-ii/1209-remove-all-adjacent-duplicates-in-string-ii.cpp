class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        int n = s.size();

        for(int i = 0; i < n; i++){
            char c = s[i];

            if(st.empty()){
                st.push({c,1});
                continue;
            }

            if(st.top().first != c){
                st.push({c,1});
            } else {
                if(st.top().second < (k-1)){
                    auto p = st.top();
                    st.pop();
                    st.push({p.first , p.second+1});
                    continue;
                }
                st.pop(); 
            }
        }

        string res = "";

        while(!st.empty()){
            auto p = st.top();
            st.pop();
            while(p.second--){
                res.push_back(p.first);
            }
        }

        reverse(res.begin(), res.end()); 
        return res;
    }
};