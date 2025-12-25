class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.rbegin(), happiness.rend());
        long long totalHappiness = 0;
        for(int i = 0; i < k; i++)
        {
            if(happiness[i] <= i)
                break;
            totalHappiness += (happiness[i] - i);
        }
        return totalHappiness;
    }
};