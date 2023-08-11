//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long int

class Solution {
private:
    ll solve(int i, int sum, int n, int coins[], vector<vector<ll>> &dp) 
    {
        if (i>=n || sum<0)  return 0;
        if (sum==0)         return 1;
        if (dp[i][sum]!=-1)     return dp[i][sum];
    
        ll take=0;
        if (coins[i]<=sum)
            take=solve(i,sum-coins[i],n,coins,dp);
        else return 0;
      
        ll not_take=solve(i+1,sum,n,coins,dp);
    
        return dp[i][sum] = take+not_take;
    }

public:
    long long int count(int coins[], int n, int sum) 
    {
        sort(coins, coins + n);
        vector<vector<ll>> dp(n, vector<ll>(sum+1,-1));
      
        return solve(0,sum,n,coins,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends