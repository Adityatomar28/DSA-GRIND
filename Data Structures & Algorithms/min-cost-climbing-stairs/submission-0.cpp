class Solution {
public:
    int solve(int n, vector<int>& cost) {

        if(n == 0) return cost[0];
        if(n == 1) return cost[1];

        // Recursive relation
        int ans1 = solve(n-1, cost);
        int ans2 = solve(n-2, cost);

        return min(ans1, ans2) + cost[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        // You can reach the top from last or second last step
        return min(
            solve(n-1, cost),
            solve(n-2, cost)
        );
    }
};