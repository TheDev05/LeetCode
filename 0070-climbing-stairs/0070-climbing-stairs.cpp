
int fun(int n, int dp[])
{
     if (n == 0)
    {
        return (1);
    }
    
     if (dp[n] != -1)
        return (dp[n]);

    int move1 = 0;
    int move2 = 0;

    if (n - 1 >= 0)
    {
        move1 = fun(n - 1, dp);
    }

    if (n - 2 >= 0)
    {
        move2 = fun(n - 2, dp);
    }

    return (dp[n] = move1 + move2);
}

class Solution
{
public:
    int climbStairs(int n)
    {
        int dp[n + 1];
        memset(dp, -1, sizeof(dp));

        return (fun(n, dp));
    }
};
