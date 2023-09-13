class Solution {
public:
    int candy(vector<int>& num) {

    int n = num.size();
    std::vector<int> res(n, 1), left, right;

    for (int i = 0; i < n; i++)
    {
        if (i - 1 >= 0 && num[i - 1] > num[i])
            left.push_back(i);
        if (i + 1 < n && num[i + 1] > num[i])
            right.push_back(i);
    }

    for (int i = left.size() - 1; i >= 0; i--)
    {
        if(res[left[i]] == 1)
        {
            int index = left[i], count = res[index];
            while (index >= 0)
            {
                res[index] = count;
                if (index - 1 < 0 || num[index - 1] <= num[index])
                    break;

                index--;
                count++;
            }
        }
    }

    for (int i = 0; i < right.size(); i++)
    {
        if(res[right[i]] == 1)
        {
            int index = right[i], count = res[index];
            while (index < n && res[index] <= count)
            {
                res[index] = count;
                if (index + 1 >= n || num[index + 1] <= num[index])
                    break;

                index++;
                count++;
            }
        }
    } 

    return accumulate(res.begin(), res.end(), 0);     
    }
};