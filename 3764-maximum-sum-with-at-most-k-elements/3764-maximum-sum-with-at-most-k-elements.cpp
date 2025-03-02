class Solution {
public:
    long long maxSum(vector<vector<int>>& num, vector<int>& limits, int k) {
        
        std::vector<std::pair<int, int>>data;
        for(int i = 0; i < num.size(); i++)
        {
            for(int j = 0; j < num[0].size(); j++)
            {
                data.push_back({num[i][j], i});
            }
        }

        sort(data.begin(), data.end(), std::greater<>());

        long long sum = 0;
        for(int i = 0; i < data.size() && i < k; i++)
        {
            if(limits[data[i].second] > 0)
                sum += data[i].first, limits[data[i].second]--;
                else k++;
        }

        return sum;

    }
};