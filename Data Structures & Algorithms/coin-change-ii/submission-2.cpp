class Solution {
public:
    int solve(int amount,vector<int>&coins,int n,vector<vector<int>>&dp){
    if(amount == 0) return 1;
    if(n < 0) 
    return 0;

    if(dp[n][amount] != -1){
    return dp[n][amount];
    }

    if(coins[n] <=  amount){
    return dp[n][amount] =  solve(amount-coins[n],coins,n,dp) +
            solve(amount,coins,n-1,dp);
    }
    return dp[n][amount] = solve(amount,coins,n-1,dp);

    }
    int change(int amount, vector<int>& coins) {
    int n = coins.size();

    vector<vector<int>>dp(n,vector<int>(amount+1,-1));
    return solve(amount,coins,n-1,dp);

    }
};
