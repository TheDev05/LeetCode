class Solution {
public:
bool validate(int temp, std::map<int, int> &data, int sum)
{
    if (data.count(temp) && data[temp] > 1)
        return true;

    int count = data[temp];
    data.erase(temp);

    auto it = data.lower_bound(temp);
    if (it != data.end())
    {
        if (abs(it->first - temp) <= sum)
            return true;
    }

    if (it != data.begin())
    {
        it--;
        if (abs(it->first - temp) <= sum)
            return true;
    }

    data[temp] = count;
    return false;
}

    bool containsNearbyAlmostDuplicate(vector<int>& num, int index, int sum) {

    std::deque<int> store;
    std::map<int, int> data;

    for (int i = 0; i < std::min(index + 1, (int)num.size()); i++)
    {
        store.push_back(num[i]);
        data[num[i]]++;
    }

    bool ok = false;
    for (auto i : store)
        if (validate(i, data, sum))
            return 1;

    data[store.front()]--;
    if (data[store.front()] == 0)
        data.erase(store.front());
    store.pop_front();

    for (int i = index + 1; i < num.size(); i++)
    {
        store.push_back(num[i]);
        data[num[i]]++;

        if (validate(num[i], data, sum))
            return 1;

        data[store.front()]--;
        if (data[store.front()] == 0)
            data.erase(store.front());
        store.pop_front();
    }

    return false;      
    }
};