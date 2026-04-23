class Solution {
public:
    int solve(vector<int>& coins, int amount, int n){
    if(amount == 0) return 0;
    if(n == 0) return INT_MAX-1;

    if(coins[n-1] <= amount){
        return min(
            1 + solve(coins,amount-coins[n-1],n),
                solve(coins,amount,n-1));
    }
    else{
        return solve(coins,amount,n-1);
    }
    
    }
    int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int ans = solve(coins,amount,n);
    if(ans == INT_MAX-1) return-1;
    return ans;
    }
};