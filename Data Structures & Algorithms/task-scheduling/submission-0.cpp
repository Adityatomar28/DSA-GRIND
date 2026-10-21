class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);

        for(char task:tasks){
            freq[task-'A']++;
        }
        priority_queue<int>pq;

        for(int count:freq){
            if(count > 0){
            pq.push(count);
            }
        }
        int time = 0;
        while(!pq.empty()){
        vector<int>temp;
        int cycle = n+1;

        while(cycle > 0 && !pq.empty()){
            int count = pq.top();
            pq.pop();

            if(count > 1){
                temp.push_back(count-1);
            }
            time++;
            cycle--;
        }
        for(int count:temp){
            pq.push(count);
        }
        if(!pq.empty()){
            time += cycle;
        }
        }
        return time;

    }
};
