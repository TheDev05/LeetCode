class Solution {
public:
    int minCost(string text, vector<int>& data) {
        
    int sum = 0;
    for (int i = 0; i < text.size(); i++)
    {
        int index = i, max = data[index], temp = 0;
        while (index < text.size() && text[index] == text[i])
            temp += data[index], max = std::max(max, data[index]), index++;

        sum += (temp - max);
        i = index - 1;
    }
 
    return sum;      
    }
};