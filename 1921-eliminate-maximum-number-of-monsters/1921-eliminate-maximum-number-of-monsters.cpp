class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
    std::vector<double> time(dist.size());
    for (int i = 0; i < dist.size(); i++)
        time[i] = ((double)dist[i] / speed[i]);

    sort(begin(time), end(time));

    int count = 0;
    for (int i = 0; i < dist.size(); i++)
    {
        double temp = time[i] - count;
        if (temp > 0)
            count++;
        else
            break;
    }

    return count;        
    }
};