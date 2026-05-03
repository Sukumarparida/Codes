class Solution {
public:

struct cpm{
    bool operator()(pair<int,string>&a ,pair<int,string>&b){
        if(a.first != b.first){
            return a.first > b.first;
        }
        return a.second < b.second; 
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        priority_queue<pair<int,string>,vector<pair<int,string>>,cpm> pq;
        unordered_map<string,int>H;
        for(string word :words){
            H[word]++;
        }
        for(auto i : H){
            string word =i.first;
            int freq =i.second;

            pair<int,string> curr{freq ,word};

            if(pq.size()<k){
                pq.push(curr);
                continue;
            }
            if(curr.first < pq.top().first)
            continue;

            if(curr.first == pq.top().first && curr.second > pq.top().second) continue;
            pq.pop();
            pq.push(curr);
        }
        vector<string> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};