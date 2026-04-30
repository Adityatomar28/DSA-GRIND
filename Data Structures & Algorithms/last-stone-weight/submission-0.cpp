class Solution {
public:
    int solve(vector<int>stones){
    priority_queue<int> maxHeap;

    for(int it:stones){
    maxHeap.push(it);
    }
    while(maxHeap.size() > 1){
    int x = maxHeap.top();
    maxHeap.pop();

    int y = maxHeap.top();
    maxHeap.pop();

    if(x != y){
    maxHeap.push(abs(x-y));
    }
    }
    if(maxHeap.empty()) return 0;

    return maxHeap.top();

    }
    int lastStoneWeight(vector<int>& stones) {
    
    return solve(stones);
    }
};

