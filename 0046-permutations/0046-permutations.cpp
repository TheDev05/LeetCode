class Solution {
public:

int fillStorage(std::vector<int> &num, std::vector<std::vector<int>> &storage, int index)
{
    for (int i = index; i < num.size() - 1; i++)
    {
        for (int j = i + 1; j < num.size(); j++)
        {
            std::swap(num[i], num[j]);
            fillStorage(num, storage, i + 1);
            std::swap(num[i], num[j]);
        }
    }

    storage.push_back(num);
    return 0;
}


    vector<vector<int>> permute(vector<int>& num) {

    std::vector<std::vector<int>> storage;
    fillStorage(num, storage, 0);
    
    return storage;

    }
};