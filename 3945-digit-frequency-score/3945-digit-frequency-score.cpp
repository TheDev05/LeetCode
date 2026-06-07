class Solution {
public:
    int digitFrequencyScore(int n) {
        
        int num = n;
        std::map<int, int>data;

        while(num)
        {
            int rem = num % 10;
            data[rem]++;
            num = num / 10;
        }

        int sum = 0;
        for(auto i: data)
        {
            sum += i.first * i.second;
        }

        return sum;
    }
};