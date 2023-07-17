class Solution {
public:
    int getPerms(std::vector<int> &num, std::set<int> inox, std::vector<int> &temp, std::vector<std::vector<int>> &storage)
{
    int val = 12;
    for (int i = 0; i < num.size(); i++)
    {
        if (inox.count(i) == false && val != num[i])
        {
            temp.push_back(num[i]);
            inox.insert(i);

            getPerms(num, inox, temp, storage);

            inox.erase(i);
            temp.pop_back();

            val = num[i];
        }
    }

    if (temp.size() == num.size())
        storage.push_back(temp);

    return 0;
}

    vector<vector<int>> permuteUnique(vector<int>& num) {

    std::vector<std::vector<int>> storage;
    std::set<int> inox;
    std::vector<int> temp;

    std::sort(num.begin(), num.end());

    getPerms(num, inox, temp, storage);
    return storage;

    }
};