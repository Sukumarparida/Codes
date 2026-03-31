class Solution {
public:

    bool isSame(string &word , string &str2 , int i , int m){
        for(int j=0;j<m;j++){
            if(word[i+j] != str2[j]){
                return false;
            }
        }
        return true;
    }

    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int N = n + m - 1;

        string word(N, '$');
        vector<bool> canchange(N, false);

        //  process 'T'
        for(int i = 0; i < n; i++){
            if(str1[i] == 'T'){
                for(int j = 0; j < m; j++){
                    if(word[i+j] != '$' && word[i+j] != str2[j]){
                        return "";
                    }
                    word[i+j] = str2[j];
                }
            }
        }

        //  fill remaining
        for(int i = 0; i < N; i++){
            if(word[i] == '$'){
                word[i] = 'a';
                canchange[i] = true;
            }
        }

        //  process 'F'
        for(int i = 0; i < n; i++){
            if(str1[i] == 'F'){

                // If already NOT equal then  OK dhan ila udane false
                if(!isSame(word, str2, i, m)) continue;

                bool changed = false;

                // last la irndhu change pannu
                for(int k = i + m - 1; k >= i; k--){
                    if(canchange[k] == true){
                        word[k] = 'b';
                        changed = true;
                        break;
                    }
                }

                if(changed ==false)
                 {
                    return "";
                    }
            }
        }

        return word;
    }
};