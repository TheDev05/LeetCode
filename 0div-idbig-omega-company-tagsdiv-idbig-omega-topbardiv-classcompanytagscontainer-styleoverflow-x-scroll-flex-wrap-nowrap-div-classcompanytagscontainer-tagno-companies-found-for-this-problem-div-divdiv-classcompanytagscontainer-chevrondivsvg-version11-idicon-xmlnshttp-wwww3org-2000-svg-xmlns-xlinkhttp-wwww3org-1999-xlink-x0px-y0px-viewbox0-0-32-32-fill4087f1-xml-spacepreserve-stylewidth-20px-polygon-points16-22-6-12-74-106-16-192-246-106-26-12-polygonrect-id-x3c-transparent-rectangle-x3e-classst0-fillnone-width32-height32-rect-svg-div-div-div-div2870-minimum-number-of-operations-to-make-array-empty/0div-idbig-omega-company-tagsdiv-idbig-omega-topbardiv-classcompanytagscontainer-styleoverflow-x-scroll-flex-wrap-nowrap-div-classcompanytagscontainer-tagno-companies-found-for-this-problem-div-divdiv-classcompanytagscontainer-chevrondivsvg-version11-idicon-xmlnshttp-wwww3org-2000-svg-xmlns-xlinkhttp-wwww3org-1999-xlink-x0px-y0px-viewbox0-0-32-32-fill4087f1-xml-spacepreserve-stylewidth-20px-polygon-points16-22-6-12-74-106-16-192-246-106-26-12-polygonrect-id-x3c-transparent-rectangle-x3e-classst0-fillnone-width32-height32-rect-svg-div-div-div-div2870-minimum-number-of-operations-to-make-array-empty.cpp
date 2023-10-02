class Solution {
public:
    int minOperations(vector<int>& num) {
        
    std::map<int, int> data;
    for (auto i : num)
        data[i]++;

    int count = 0;
    for (auto i : data)
    {
        int sum = 0;
        for (int j = 3; j <= i.second; j += 3)
        {
            if (j > i.second)
                break;

            if ((i.second - j) % 2 == 0)
                sum = j;
        }

        if(i.second == 1) return -1;
        count += (sum / 3) + ((i.second - sum) / 2);
    }

    return count;        
    }
};

// 2 3 22 23 33 223 233 2223 2233 2333 3333 22333
// 2 3 4 5 6 7 8 9 10 11 12 13