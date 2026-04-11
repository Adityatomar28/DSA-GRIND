class Solution {
public: 
    int solve(int n){
    if(n == 0) return 0;

    if(n == 1) return 1;
    if(n == 2) return 2;
    
    int ans1 =  solve(n-1);
    int ans2 =  solve(n-2);

    return ans1+ans2;

    }
    int climbStairs(int n) {
    return solve(n);
    }
};
