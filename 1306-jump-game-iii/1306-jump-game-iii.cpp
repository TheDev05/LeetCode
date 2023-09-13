class Solution {
public:
    bool canReach(vector<int>& num, int start) {
        
    int n = num.size();
    if(num[start] == 0) return true;
        
    std::vector<int> vis(n, 0);
    std::queue<int> inox;

    inox.push(start);
    vis[start] = 1;

    while (inox.size())
    {
        int index = inox.front();
        inox.pop();

        int right = index + num[index];
        int left = index - num[index];

        if (right < n && vis[right] == 0)
        {
            if (num[right] == 0)
                return true;

            inox.push(right);
            vis[right] = 1;
        }

        if (left >= 0 && vis[left] == 0)
        {
            if (num[left] == 0)
                return true;

            inox.push(left);
            vis[left] = 1;
        }
    }
        
    return false;
    }
};