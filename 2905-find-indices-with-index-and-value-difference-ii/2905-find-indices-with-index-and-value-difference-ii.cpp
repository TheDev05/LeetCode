class Solution {
public:
    vector<int> findIndices(vector<int>& num, int deltaIndex, int deltaSum) {

    std::map<int, int> data;
    for (auto i : num)
        data[i]++;

    std::deque<int> store;
    for (int i = 0; i < std::min(deltaIndex + 1, (int)num.size()); i++)
    {
        store.push_back(num[i]);

        data[num[i]]--;
        if (data[num[i]] == 0)
            data.erase(num[i]);
    }

    data[store.back()]++;

    int delta1 = data.begin()->first;
    int delta2 = data.rbegin()->first;

    std::cout << store.size();

    int index1 = -1, index2 = -1;
    if ((store.size() == deltaIndex + 1) && (abs(delta1 - store.front()) >= deltaSum || abs(delta2 - store.front()) >= deltaSum))
        index1 = 0;

    if (index1 == -1)
    {
        for (int i = deltaIndex + 1; i < num.size(); i++)
        {
            data[store.back()]--;
            if (data[store.back()] == 0)
                data.erase(store.back());

            store.pop_front();
            store.push_back(num[i]);

            int delta1 = data.begin()->first;
            int delta2 = data.rbegin()->first;

            if (store.size() == deltaIndex + 1 && (abs(delta1 - store.front()) >= deltaSum || abs(delta2 - store.front()) >= deltaSum))
            {
                index1 = i - deltaIndex;
                break;
            }
        }
    }

    for (int i = index1; i < num.size(); i++)
    {
        if (abs(index1 - i) >= deltaIndex && abs(num[index1] - num[i]) >= deltaSum)
        {
            index2 = i;
            break;
        }
    }

    return {index1, index2};        
    }
};