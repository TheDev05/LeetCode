//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
        int getPath(std::vector<std::vector<int>> &num, std::string text, std::vector<std::string> &result, int i, int j)
{
    if (num[i][j] == 0)
        return 0;

    if (i == num.size() - 1 && j == num[0].size() - 1)
    {
        result.push_back(text);
        return 0;
    }

    if (i != 0)
    {
        int temp = num[i][j];
        num[i][j] = 0;

        text += 'U';
        getPath(num, text, result, i - 1, j);
        text.erase(text.size() - 1);

        num[i][j] = temp;
    }

    if (i != num.size() - 1)
    {
        int temp = num[i][j];
        num[i][j] = 0;

        text += 'D';
        getPath(num, text, result, i + 1, j);
        text.erase(text.size() - 1);

        num[i][j] = temp;
    }

    if (j != 0)
    {
        int temp = num[i][j];
        num[i][j] = 0;

        text += 'L';
        getPath(num, text, result, i, j - 1);
        text.erase(text.size() - 1);

        num[i][j] = temp;
    }

    if (j != num[0].size() - 1)
    {
        int temp = num[i][j];
        num[i][j] = 0;

        text += 'R';
        getPath(num, text, result, i, j + 1);
        text.erase(text.size()-1);

        num[i][j] = temp;
    }

    return 0;
}


    vector<string> findPath(vector<vector<int>> &num, int n) {
        
    // Your code goes here
    std::vector<std::string> result;
    std::string text;

    if (num[0][0] == 0 || num[n - 1][n - 1] == 0)
        return result;

    getPath(num, text, result, 0, 0);

    return result;
    
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends