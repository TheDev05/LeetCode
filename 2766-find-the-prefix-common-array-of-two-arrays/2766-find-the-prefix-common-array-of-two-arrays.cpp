class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& num1, vector<int>& num2) {
    
    std::map<int, int> first, second;
    std::vector<int> result;

    int sum = 0;
    for (int i = 0; i < num1.size(); i++)
    {
        first[num1[i]]++;
        second[num2[i]]++;

        if (second[num1[i]])
            sum++;
        if (first[num2[i]])
            sum++;

        if (num1[i] == num2[i])
            sum--;

        result.push_back(sum);
    }

    return result;

    }
};