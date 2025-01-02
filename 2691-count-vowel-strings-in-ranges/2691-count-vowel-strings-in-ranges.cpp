class Solution {
public:
bool isCheck(std::string text)
{
    bool ok1 = false, ok2 = false;
    if (text[0] == 'a' || text[0] == 'e' || text[0] == 'i' || text[0] == 'o' || text[0] == 'u')
        ok1 = true;
    if (text[text.size() - 1] == 'a' || text[text.size() - 1] == 'e' || text[text.size() - 1] == 'i' || text[text.size() - 1] == 'o' || text[text.size() - 1] == 'u')
        ok2 = true;

    if(ok1 && ok2) return true;
    return false;
}
    
    vector<int> vowelStrings(vector<string>& num, vector<vector<int>>& data) {

    std::vector<int> temp(num.size(), 0);

    int sum = 0;
    for (int i = 0; i < num.size(); i++)
    {
        if (isCheck(num[i]))
            sum++;

        temp[i] = sum;
    }

    std::vector<int> result;
    for (int i = 0; i < data.size(); i++)
    {
        int left = data[i][0];
        int right = data[i][1];

        int res = temp[right] - temp[left];
        if (isCheck(num[left]))
            res++;

        result.push_back(res);
    }


    for (auto i : result)
        std::cout << i << " ";

    return result;

    }
};