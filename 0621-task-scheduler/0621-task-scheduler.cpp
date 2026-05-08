class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char,int> freq;
        unordered_map<char,int>free;
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]]++;
            free[tasks[i]] =1;
        }
        priority_queue<pair<int,char>>pq;
        int seat =1;
        for(auto i : freq){
            int freq =i.second;
            char child = i.first;
            pq.push({freq,child});
        }
        while(!pq.empty()){
            vector<pair<int,char>>pulled;
            while(!pq.empty()){
                pair<int,char> p =pq.top();
                pq.pop();
                int fr =p.first;
                int child =p.second;
                if(free[child] <= seat){
                    if(p.first >1)
                        pq.push({p.first-1,p.second});
                        free[p.second] = seat+n+1;
                     break;   
                }else{
                    pulled.push_back(p);
                }
            }
            for(int i=0;i<pulled.size();i++){
                  pq.push(pulled[i]);
            }
         seat++;
        }
        return seat-1;
    }
};