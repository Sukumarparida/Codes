class Solution {
public:

    struct cmp{
        bool operator()(pair<int,char>&a,pair<int,char>&b){
            if(a.first != b.first){
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    };
    string reorganizeString(string s) {
        int n =s.size();
        priority_queue<pair<int,char>,vector<pair<int,char>>,cmp>pq;
        unordered_map<char,int>H;
        for(int i=0;i<n;i++){
            H[s[i]]++;
        }
        for(auto x : H){
            char ch =x.first;
            int freq =x.second;
            pq.push({freq,ch});
        }
        int seat=0;
        string res="";
        while(!pq.empty()){
            auto p =pq.top();
            pq.pop();
            if(seat ==0 || res[seat-1] !=p.second){
                res.push_back(p.second);
                p.first--;
                seat++;
                if(p.first >0)
                pq.push(p);
            }
            else{
                if(pq.empty())
                return "";
                auto p1 =pq.top();
                pq.pop();
                res.push_back(p1.second);
                p1.first--;
                seat++;
                if(p1.first>0)
                pq.push(p1);
                pq.push(p);
            }
        }
        return res;
    }
};