class Solution {
public:
    int longestConsecutive(vector<int>& num) 
    {
        std::set<int> st;
        for (auto i : num)
            st.insert(i);

        int max = 0, last = 0;
        for (auto i = st.begin(); i != st.end(); i++)
        {
            int count = 1;
            if (i != st.begin())
            {
                while (i != st.end() && std::abs(*i - last) == 1)
                {
                    count++;
                    last = *i;

                    i++;
                }
            }

            last = *i;

            max = std::max(max, count);
            if (i == st.end())
                break;
        }

        return max;
    }
};