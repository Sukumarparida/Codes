class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>freq;
        unordered_map<char,int>free;
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]]++;
            free[tasks[i]] =1;
        }
        priority_queue<pair<int,char>> pq;
        for(auto i : freq){
            pq.push({i.second , i.first});
        }
        int seat =1;
        while(!pq.empty()){
            vector<pair<int,char>> pulled;
            while(!pq.empty()){
                pair<int,char> p =pq.top();
                pq.pop();
                int fre =p.first;
                char child=p.second;
                if(free[child] <= seat){
                    if(p.first >1)
                    pq.push({p.first-1,p.second});
                    free[child] =seat + n + 1;
                    break;
                }else{
                    pulled.push_back(p);
                }
            }
            seat++;
            for(int i=0;i<pulled.size();i++)
            pq.push(pulled[i]);
        }
        return seat-1;
    }
};