class Solution {
public:

    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> adj;

        unordered_map<int, int> indegree;

        // build graph
        for(auto &edge : prerequisites) {

            int a = edge[0];
            int b = edge[1];

            // b -> a
            adj[b].push_back(a);

            indegree[a]++;
        }

        queue<int> q;

        // nodes with indegree 0
        for(int i = 0; i < numCourses; i++) {

            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            count++;

            for(auto ngbr : adj[node]) {

                indegree[ngbr]--;

                if(indegree[ngbr] == 0) {
                    q.push(ngbr);
                }
            }
        }

        return count == numCourses;
    }
};