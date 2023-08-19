//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&num){
	    // Code here
	    
	int n = num.size();  
    for (auto &i : num)
    {
        for (auto &j : i)
        {
            if (j == -1)
                j = 1e7;
        }
    }

    for (int v = 0; v < n; v++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                num[i][j] = std::min(num[i][j], num[i][v] + num[v][j]);
            }
        }
    }
    
    for (auto &i : num)
    {
        for (auto &j : i)
        {
            if (j == 1e7)
                j = -1;
        }
    }

	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends