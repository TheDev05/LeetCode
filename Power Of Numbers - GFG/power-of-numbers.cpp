//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007

// } Driver Code Ends

#define mod 1000000007
#define ll long long

class Solution{
    public:
    
ll power(ll a, ll b, ll MOD){
    
    ll ans = 1;
    a = a % MOD;
    
    while(b > 0){
        
        if(b % 2 == 1){
            ans = (ans * a) % MOD;
        }
        
        a = (a * a) % MOD;
        b = b / 2;
    }
    
    return ans;
}
    
    ll power(ll n, ll r)
    {
       return power(n,r,mod);
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends