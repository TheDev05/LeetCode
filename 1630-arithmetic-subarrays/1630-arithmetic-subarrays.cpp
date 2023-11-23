class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& num, vector<int>& l, vector<int>& r) {
        std::vector<bool> res;
        for (int i = 0; i < l.size(); i++)
        {
            std::multiset<int> temp;
            for (int j = l[i]; j <= r[i]; j++)
                temp.insert(num[j]);

            if (temp.size() == 1)
            {
                res.push_back(true);
                continue;
            }

            auto it = temp.begin();
            int d = 0, prev = 0, inox = *it++;

            d = *it - inox;
            bool ok = false;

            for (auto k : temp)
            {
                if (!ok)
                    prev = k, ok = true;
                else if (k - prev != d)
                {
                    ok = false;
                    break;
                }

                prev = k;
            }

            if (ok)
                res.push_back(true);
            else
                res.push_back(false);
        } 
        
        return res;
    }
};