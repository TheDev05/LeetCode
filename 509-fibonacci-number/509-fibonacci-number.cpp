class Solution {
public:
    
    int fun(int n, int dp[])
    {
        if(n<=1)return(n);
        if(dp[n]!=-1)return(dp[n]);
        return(dp[n]=(fun(n-1,dp)+fun(n-2,dp)));
    }
    
    int fib(int n) {
        
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        return(fun(n,dp));
    }
};