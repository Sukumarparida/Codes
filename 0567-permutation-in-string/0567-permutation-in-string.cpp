class Solution {
public:

    bool isfreqsame(int s1[] , int s2[]){
        for(int i=0;i<26; i++){
            if(s1[i] != s2[i]) return false;
        
    }
    return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freq[26]={0};
        for(int i=0;i<s1.length(); i++){
            freq[s1[i] - 'a']++;
        }
        int windsize=s1.length();
        
        for(int i=0; i<s2.length(); i++){
           int idx=i, windidx=0;
           int windfreq[26]={0};
        while(windidx < windsize && idx < s2.length()){
            windfreq[s2[idx] - 'a']++;
            idx++;
            windidx++;
        }
        if(isfreqsame(freq , windfreq)){
        return true;
        }
        }
        return false;
    }
};