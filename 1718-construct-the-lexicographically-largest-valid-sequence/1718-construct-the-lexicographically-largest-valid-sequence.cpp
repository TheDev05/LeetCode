class Solution {
public:
int getStore(int n, std::vector<int> &store, std::set<int> &exist, int index)
{
    if (index >= store.size())
    {
        return true;
    }

    if (store[index] == 0)
    {
        for (int i = n; i >= 1; i--)
        {
            if (exist.count(i) == false)
            {
                if (i == 1)
                {
                    exist.insert(i);
                    store[index] = i;

                    if (getStore(n, store, exist, index + 1))
                        return true;

                    exist.erase(i);
                    store[index] = 0;
                }
                else if ((index + i) < store.size() && store[index + i] == 0)
                {
                    exist.insert(i);
                    store[index] = i;
                    store[index + i] = i;

                    if (getStore(n, store, exist, index + 1))
                        return true;

                    exist.erase(i);
                    store[index] = 0;
                    store[index + i] = 0;
                }
            }
        }
    }
    else if (getStore(n, store, exist, index + 1))
        return true;

    return false;
}

    
    vector<int> constructDistancedSequence(int n) {
    std::vector<int> store((n * 2) - 1, 0);
    std::set<int> exist;

    getStore(n, store, exist, 0);
    return store;
        
    }
};